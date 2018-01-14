/*
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (32.01%)
 * Total Accepted:    78.9K
 * Total Submissions: 246.4K
 * Testcase Example:  '""\n"a"'
 *
 * 
 * Given a string S and a string T, count the number of distinct subsequences
 * of S which equals T.
 * 
 * 
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 * 
 * 
 * 
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 * 
 * 
 * Return 3.
 * 
 */
/*
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (32.01%)
 * Total Accepted:    78.9K
 * Total Submissions: 246.4K
 * Testcase Example:  '""\n"a"'
 *
 * 
 * Given a string S and a string T, count the number of distinct subsequences
 * of S which equals T.
 * 
 * 
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 * 
 * 
 * 
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 * 
 * 
 * Return 3.
 * 
 */
class Solution {
public:
    int numDistinct(string s, string t) {
        if (t.size() == 0 || s.size() == 0) {
            return 0;
        }
        vector<int> cnt(s.size(), 0);
        int val = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == t[0]) {
                val += 1;
            }
            cnt[j] = val;
        }
        for (int i = 1; i < t.size(); i++) {
            int val = 0;
            vector<int> tmp(s.size(), 0);
            for (int j = 1; j < s.size(); j++) {
                if (s[j] == t[i]) {
                    val += cnt[j-1];
                }
                tmp[j] = val;
            }
            cnt = move(tmp);
        }
        return cnt.back();
    }
};


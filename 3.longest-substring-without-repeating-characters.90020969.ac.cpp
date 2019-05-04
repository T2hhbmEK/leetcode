/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters
 *
 * Medium (24.11%)
 * Total Accepted:    289158
 * Total Submissions: 1199457
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.length()) return 0;
        int r = 1;
        int p1 = 0, p2 = 1;
        unordered_map<char,int> pool = {{s[p1],p1}};
        while(p2<s.length()) {
            auto search = pool.find(s[p2]);
            if (search!=pool.end()) {
                r = p2-p1>r? p2-p1:r;
                if (search->second >= p1) {
                    p1 = search->second +1;
                }
                pool.erase(s[p2]);
            }
            pool.insert({s[p2],p2});
            p2++;
        }
        r = p2-p1>r? p2-p1:r;
        return r;
    }
};

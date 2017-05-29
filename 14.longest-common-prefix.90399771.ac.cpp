/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix
 *
 * Easy (31.24%)
 * Total Accepted:    171455
 * Total Submissions: 548743
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string r = "";
        if (strs.size() == 0) return r;
        if (strs.size() == 1) return strs[0];
        for (int i = 0; i < strs[0].size(); i++) {
            char a = strs[0][i];
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != a) {
                    return strs[1].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};

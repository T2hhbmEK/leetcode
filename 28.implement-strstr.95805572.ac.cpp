/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr
 *
 * Easy (27.68%)
 * Total Accepted:    178013
 * Total Submissions: 643194
 * Testcase Example:  '""\n""'
 *
 * 
 * Implement strStr().
 * 
 * 
 * Returns the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> kmp(needle.size(),-1);
        if (needle.size() == 0) return 0;
        int i = 1;
        int j = 0;
        for (; i < needle.size();) {
            if (needle[i] == needle[j]) {
                if (needle[i+1] == needle[j+1]) {
                    kmp[i] = kmp[j];
                } else {
                    kmp[i] = j;
                }
                i++;
                j++;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = kmp[j-1]+1;
                }
            }
        }
        i = 0;
        j = 0;
        for (;i < haystack.size();) {
            if (haystack[i] == needle[j]) {
                if (j == needle.size()-1) {
                    return i-j;
                } else {
                    i++;
                    j++;
                }
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = kmp[j-1]+1;
                }
            }
        }
        return -1;
    }
};

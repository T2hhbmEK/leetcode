/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say
 *
 * Easy (33.77%)
 * Total Accepted:    131916
 * Total Submissions: 390640
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * 
 * 
 * Given an integer n, generate the nth sequence.
 * 
 * 
 * 
 * Note: The sequence of integers will be represented as a string.
 * 
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 1) return "1";
        string s = countAndSay(n-1);
        string r = "";
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            count++;
            if (i == s.size()-1 || s[i+1] != s[i]) {
                r += '0'+count;
                r += s[i];
                count = 0;
            }
        }
        return r;
    }
};

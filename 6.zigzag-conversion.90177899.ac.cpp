/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion
 *
 * Medium (26.51%)
 * Total Accepted:    149828
 * Total Submissions: 565211
 * Testcase Example:  '""\n1'
 *
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * string convert(string text, int nRows);
 * 
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * 
 */
class Solution {
public:
    string convert(string s, int n) {
        if (n<=1) return s;
        string r;
        for(int j=0;j<s.size();j+=2*(n-1)) r+=s[j];
        for(int i=1;i<n-1;i++){
            for(int j=i;j<s.size();j+=2*(n-1)){
                r+=s[j];
                if(j+2*(n-1)-2*i<s.size()){
                    r+=s[j+2*(n-1)-2*i];
                }
            }
        }
        if (n>1) for(int j=n-1;j<s.size();j+=2*(n-1))r+=s[j];
        return r;
    }
};

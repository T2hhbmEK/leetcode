/*
 * [12] Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman
 *
 * Medium (43.97%)
 * Total Accepted:    102750
 * Total Submissions: 233692
 * Testcase Example:  '1'
 *
 * Given an integer, convert it to a roman numeral.
 * 
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    string intToRoman(int num) {
        string result;
        string Roman = "IVXLCDM";
        int i = 0;
        while (num > 0) {
            string r;
            int j = num%10;
            num = num/10;
            switch (j) {
                case 1:
                case 2:
                case 3: for(;j>0;j--) r += Roman[i];break;
                case 4: r = {Roman[i],Roman[i+1]};break;
                case 5: 
                case 6:
                case 7:
                case 8: r += Roman[i+1];for(;j>5;j--) r += Roman[i];break;
                case 9: r = {Roman[i],Roman[i+2]};break;
                default: ;
            }
            result = r+result;
            i+=2;
        }
        return result;
    }
};

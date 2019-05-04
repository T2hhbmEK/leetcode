/*
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer
 *
 * Easy (44.96%)
 * Total Accepted:    146818
 * Total Submissions: 326548
 * Testcase Example:  '"DCXXI"'
 *
 * Given a roman numeral, convert it to an integer.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> Roman = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int r = 0;
        int pr = 0;
        for (int i = s.size()-1; i >=0; i--) {
            int add = Roman.find(s[i])->second;
            r += add<pr? -add:add;
            pr = add;
        }
        return r;
    }
};

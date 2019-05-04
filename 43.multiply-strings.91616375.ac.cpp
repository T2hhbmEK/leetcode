/*
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings
 *
 * Medium (26.64%)
 * Total Accepted:    99019
 * Total Submissions: 371717
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        string r = "0";
        if (num1 == "0" || num2 == "0") return r;
        for (int i = 0; i < num2.size(); i++) {
            r = add(r,multiply(num1,num2[i]-'0')+string(num2.size()-1-i,'0'));
        }
        return r;
    }
    string multiply(string num1, int num2, int carry = 0) {
        int a = popint(num1);
        int c = a*num2+carry;
        carry = c/10;
        c = c%10;
        if (!num1.size() && !carry) {
            return string(1,(char)('0'+c));
        } else {
            return multiply(num1, num2, carry) + (char)('0'+c);
        }
    }
    string add(string num1, string num2, int carry = 0) {
        int a = popint(num1), b = popint(num2);
        int c = a+b+carry;
        carry = c/10;
        c = c%10;
        if (!num1.size() && !num2.size() && !carry) {
            return string(1,(char)('0'+c));
        } else {
            return add(num1, num2, carry) + (char)('0'+c);
        }
    }
    int popint(string& num) {
        int r = num.size() ? num.back()-'0' : 0;
        if (num.size()) num.pop_back();
        return r;
    }
};

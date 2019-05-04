/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses
 *
 * Medium (43.69%)
 * Total Accepted:    142360
 * Total Submissions: 325834
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> r;
        string s(n,'('),tmp(n,')');
        s += tmp;
        r.push_back(s);
        while (nextParenthesis(s)) {
            if (isValid(s))
                r.push_back(s);
        }
        return r;
    }
    bool nextParenthesis(string & s){
        for (int i = (int)s.size()-2; i >= 0; i--) {
            if (s[i] < s[i+1]) {
                swap(s[i], s[i+1]);
                reverse(s.begin()+i+2, s.end());
                return true;
            }
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> stk;
        for (auto&& c:s) {
            if (c == '(') {
                stk.push(c);
            } else if (stk.size() == 0) {
                return false;
            } else if (c == ')' && stk.top() == '(') {
                stk.pop();
            } else { return false; }
        }
        if (stk.size() == 0) {
            return true;
        } else { return false; }
    }
};

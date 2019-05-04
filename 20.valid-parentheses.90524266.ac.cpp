/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses
 *
 * Easy (33.04%)
 * Total Accepted:    197007
 * Total Submissions: 596307
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto&& c:s) {
            if (c == '(' || c == '[' || c =='{') {
                stk.push(c);
            } else if (stk.size() == 0) {
                return false;
            } else if ((c == ')' && stk.top() == '(') //
                    || (c == ']' && stk.top() == '[') //
                    || (c == '}' && stk.top() == '{') ) {
                stk.pop();
            } else { return false; }
        }
        if (stk.size() == 0) {
            return true;
        } else { return false; }
    }
};

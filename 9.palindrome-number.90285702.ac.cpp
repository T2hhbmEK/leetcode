/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number
 *
 * Easy (34.78%)
 * Total Accepted:    207995
 * Total Submissions: 597951
 * Testcase Example:  '-2147483648'
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * click to show spoilers.
 * 
 * Some hints:
 * 
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the
 * restriction of using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the
 * problem "Reverse Integer", you know that the reversed integer might
 * overflow. How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || (x!=0 && x%10==0)) return false;
        int y=0;
        while (x>y) {
            y *= 10;
            y += x%10;
            x = x/10;
        }
        return (x == y || x==y/10);
    }
};

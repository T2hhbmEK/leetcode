/*
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers
 *
 * Medium (15.96%)
 * Total Accepted:    99458
 * Total Submissions: 623190
 * Testcase Example:  '0\n1'
 *
 * 
 * Divide two integers without using multiplication, division and mod
 * operator.
 * 
 * 
 * If it is overflow, return MAX_INT.
 * 
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        bool indicator = (dividend > 0) xor (divisor > 0);
        unsigned int undividend = (dividend >= 0) ? dividend : -dividend;
        unsigned int undivisor = (divisor >= 0) ? divisor : -divisor;
        unsigned int r = 0;
        while (undividend >= undivisor) {
            unsigned int j = 1;
            unsigned int tmp = undivisor;
            while ((tmp<<1) != 0 && undividend >= (tmp<<1)) {
                j = j<<1;
                tmp = tmp<<1;
            }
            r += j;
            undividend -= tmp;
        }
        if (!indicator) {
            return (r == INT_MIN) ? INT_MAX : (int)r;
        } else {
            return -(int)r;
        }
    }
};

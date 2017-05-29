/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n
 *
 * Medium (26.59%)
 * Total Accepted:    147451
 * Total Submissions: 554462
 * Testcase Example:  '8.88023\n3'
 *
 * Implement pow(x, n).
 *
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (x < 0) {
            double r = exp(n*log(-x));
            return n % 2 == 0 ? r : -r;
        }
        return exp(n*log(x));
    }
};

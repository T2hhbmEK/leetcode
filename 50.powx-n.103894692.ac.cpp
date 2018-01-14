/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (26.02%)
 * Total Accepted:    190.7K
 * Total Submissions: 733K
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n).
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 */
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


/*
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (34.26%)
 * Total Accepted:    62.1K
 * Total Submissions: 181.3K
 * Testcase Example:  '0\n0'
 *
 * Given a range [m, n] where 0 
 * 
 * 
 * For example, given the range [5, 7], you should return 4.
 * 
 * 
 * Credits:Special thanks to @amrsaqr for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0 || n == 0) {
            return 0;
        } else if (m == n) {
            return m;
        }
        int a = rangeBitwiseAnd(m >> 1, n >> 1);
        if (m >> 1 == n >> 1) {
            a = (a << 1) | ( (m & 0x1) & (n & 0x1) );
        } else {
            a = a << 1;
        }
        return a;
    }
};

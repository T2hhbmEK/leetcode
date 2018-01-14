/*
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (33.17%)
 * Total Accepted:    69.2K
 * Total Submissions: 208.8K
 * Testcase Example:  '1'
 *
 * 
 * Write a program to find the n-th ugly number.
 * 
 * 
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * 
 * 
 * Note that 1 is typically treated as an ugly number, and n does not exceed
 * 1690.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
/*
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (33.17%)
 * Total Accepted:    69.2K
 * Total Submissions: 208.8K
 * Testcase Example:  '1'
 *
 * 
 * Write a program to find the n-th ugly number.
 * 
 * 
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * 
 * 
 * Note that 1 is typically treated as an ugly number, and n does not exceed
 * 1690.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_numbers = {1};
        vector<int> last_ids = {0, 0, 0};
        vector<int> factors = {2, 3, 5};
        int i = 0;
        while (i < n) {
            i++;
            vector<int> next_ugly_numbers;
            for (int j = 0; j < factors.size(); j++) {
                int f = factors[j];
                int last_id = last_ids[j];
                next_ugly_numbers.push_back(ugly_numbers[last_id]*f);
            }
            int next_ugly_number = *min_element(next_ugly_numbers.begin(), next_ugly_numbers.end());
            ugly_numbers.push_back(next_ugly_number);
            for (int j = 0; j < factors.size(); j++) {
                int f = factors[j];
                int last_id = last_ids[j];
                if (ugly_numbers[last_id]*f <= next_ugly_number) {
                    last_ids[j]++;
                }
            }
        }
        return ugly_numbers[n-1];
    }
};


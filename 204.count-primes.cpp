/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (26.65%)
 * Total Accepted:    140.3K
 * Total Submissions: 526.4K
 * Testcase Example:  '0'
 *
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
 public:
  int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    int cnt = 0;
    int sqrt_n = sqrt(n);
    for (int i = 2; i < n; i++) {
      if (isPrime[i]) {
        cnt++;
        if (i <= sqrt_n) {
          for (int j = i * i; j < n; j += i) {
            isPrime[j] = false;
          }
        }
      }
    }
    return cnt;
  }
};

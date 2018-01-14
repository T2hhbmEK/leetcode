/*
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (29.19%)
 * Total Accepted:    96K
 * Total Submissions: 328.7K
 * Testcase Example:  '1\n1'
 *
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 
 * Given n and k, return the kth permutation sequence.
 * 
 * Note: Given n will be between 1 and 9 inclusive.
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        string r, t;
        r.reserve(n);
        t.reserve(n);
        int a = 1;
        for (int i = 0; i < n; i++) {
            t += '1' + i;
            a *= i + 1;
        }
        int b = k-1;
        for (int i = 0; i < n; i++) {
            a /= n - i;
            int j = b/a;
            b %= a;
            r += t[j];
            t.erase(j,1);
        }
        return r;
    }
};

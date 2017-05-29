/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest
 *
 * Medium (30.85%)
 * Total Accepted:    124889
 * Total Submissions: 404796
 * Testcase Example:  '[0,0,0]\n1'
 *
 * Given an array S of n integers, find three integers in S such that the sum
 * is closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * 
 * 
 * ⁠   For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 * ⁠   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
        sort(v.begin(),v.end());
        int r = v[0]+v[1]+v[2];
        for (int i = 0; i <= v.size()-3; i++) {
            int j = i+1;
            int k = (int)v.size()-1;
            while (j < k) {
                if (abs(v[i] + v[j] + v[k] - target) < abs(r-target)) {
                    r = v[i] + v[j] + v[k];
                }
                if (v[i] + v[j] + v[k] < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return r;
    }
};

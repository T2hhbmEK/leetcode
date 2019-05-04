/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum
 *
 * Medium (21.50%)
 * Total Accepted:    208239
 * Total Submissions: 968641
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> r;
        if (v.size() < 3) return r;
        sort(v.begin(),v.end());
        for (int i = 0; i <= v.size()-3 && v[i]+v[i+1]+v[i+2] <= 0; i++) {
            int j = i+1;
            int k = v.size()-1;
            while (j < k) {
                if (v[i] + v[j] + v[k] == 0) {
                    r.push_back({v[i],v[j],v[k]});
                    while(j < k && v[j+1] == v[j]) j++;j++;
                    while(j < k && v[k-1] == v[k]) k--;k--;
                }
                else if (v[i] + v[j] + v[k] < 0) {
                    j++;
                } else {
                    k--;
                }
            }
            while(i <= v.size() - 3 && v[i+1] == v[i]) i++;
        }
        return r;
    }
};

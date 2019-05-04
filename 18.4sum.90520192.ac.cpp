/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum
 *
 * Medium (26.34%)
 * Total Accepted:    114363
 * Total Submissions: 434246
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such
 * that a + b + c + d = target? Find all unique quadruplets in the array which
 * gives the sum of target.
 * 
 * Note: The solution set must not contain duplicate quadruplets.
 * 
 * 
 * 
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> r;
        sort(nums.begin(),nums.end());
        // r.push_back(nums);
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                int l = N-1;
                int k = j+1;
                while (k < l) {
                    while (l > 0 && nums[i] + nums[j] + nums[k] + nums[l] > target) {
                        l--;
                    }
                    while (k < N-1 && nums[i] + nums[j] + nums[k] + nums[l] < target) {
                        k++;
                    }
                    if (k < l && nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        vector<int> tmp = {nums[i], nums[j], nums[k], nums[l]};
                        r.push_back(tmp);
                        while(l > k+1 && nums[l-1] == nums[l]) {
                            l--;
                        }
                        l--;
                        while(k < l-1 && nums[k+1] == nums[k]) {
                            k++;
                        }
                        k++;
                    }
                }
                while(j < N-1 && nums[j+1] == nums[j]) {
                    j++;
                }
            }
            while(i < N-1 && nums[i+1] == nums[i]) {
                i++;
            }
        }
        return r;
    }
};

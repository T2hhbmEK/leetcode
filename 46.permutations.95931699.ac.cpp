/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations
 *
 * Medium (42.43%)
 * Total Accepted:    160973
 * Total Submissions: 379392
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a collection of distinct numbers, return all possible permutations.
 * 
 * 
 * 
 * For example,
 * [1,2,3] have the following permutations:
 * 
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> prefix;
        permute(nums,prefix,results);
        return results;
    }
    
    void permute(vector<int>& nums, vector<int> &prefix, vector<vector<int>> &results) {
        if (nums.size() <= 0) {
            results.push_back(prefix);
            return;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                int x = nums[i];
                nums.erase(nums.begin()+i);
                prefix.push_back(x);
                permute(nums, prefix, results);
                prefix.pop_back();
                nums.insert(nums.begin()+i,x);
            }
        }
        return;
    }
};

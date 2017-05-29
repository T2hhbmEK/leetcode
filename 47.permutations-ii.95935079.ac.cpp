/*
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii
 *
 * Medium (32.03%)
 * Total Accepted:    115418
 * Total Submissions: 360326
 * Testcase Example:  '[1,1,2]'
 *
 * 
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * 
 * 
 * For example,
 * [1,1,2] have the following unique permutations:
 * 
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> prefix;
        sort(nums.begin(), nums.end());
        permuteUnique(nums, prefix, results);
        return results;
    }
    
    void permuteUnique(vector<int>& nums, vector<int>& prefix, vector<vector<int>>& results) {
        if (nums.size() <= 0) {
            results.push_back(prefix);
            return;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                int x = nums[i];
                if (i == 0 || x != nums[i-1]) {
                    nums.erase(nums.begin()+i);
                    prefix.push_back(x);
                    permuteUnique(nums, prefix, results);
                    prefix.pop_back();
                    nums.insert(nums.begin()+i, x);
                }
            }
        }
        return;
    }
};

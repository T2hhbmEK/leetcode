/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation
 *
 * Medium (28.56%)
 * Total Accepted:    106714
 * Total Submissions: 373628
 * Testcase Example:  '[1]'
 *
 * 
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = (int)nums.size()-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                int j = (int)nums.size()-1;
                for(;j > i && nums[j] <= nums[i];j--);
                if (j > i) swap(nums[i], nums[j]);
                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};

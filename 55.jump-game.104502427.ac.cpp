/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (31.75%)
 * Total Accepted:    256.1K
 * Total Submissions: 806.6K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */
/*
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game
 *
 * Medium (29.40%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[0]'
 *
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 *
 * Determine if you are able to reach the last index.
 *
 *
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 *
 * A = [3,2,1,0,4], return false.
 *
 */
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    if (nums.size() < 1) {
      return false;
    }
    int max = 0;
    for (int i = 0; i <= max && i < nums.size(); i++) {
      max = nums[i] + i > max ? nums[i] + i : max;
    }
    if (max >= nums.size() - 1) {
      return true;
    }
    return false;
  }
};


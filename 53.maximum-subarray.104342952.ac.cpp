/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (43.39%)
 * Total Accepted:    513.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray
 *
 * Easy (39.33%)
 * Total Accepted:    191821
 * Total Submissions: 487740
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 *
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest sum.
 *
 *
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 *
 *
 * click to show more practice.
 *
 * More practice:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        }
        vector<int> sums(nums);
        for (int i = 1; i < sums.size(); i++) {
            sums[i] = sums[i-1] + sums[i];
        }
        int result = sums[0];
        int min_sum = 0;
        for (int i = 0; i < sums.size(); i++ ) {
            if (sums[i] - min_sum > result) {
                result = sums[i] - min_sum;
            }
            if (sums[i] < min_sum) {
                min_sum = sums[i];
            }
        }
        return result;
    }
};


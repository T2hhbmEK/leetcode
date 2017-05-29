/*
 * [34] Search for a Range
 *
 * https://leetcode.com/problems/search-for-a-range
 *
 * Medium (31.18%)
 * Total Accepted:    132151
 * Total Submissions: 423882
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers sorted in ascending order, find the starting and
 * ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * 
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 * 
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i,j,k;
        vector<int> r = {-1,-1};
        if (nums.size() <= 0) return r;
        i = 0;
        j = nums.size()-1;
        k = (i+j)/2;
        while (i<j) {
            if (nums[k] < target) {
                i = k+1;
            } else {
                j = k;
            }
            k = (i+j)/2;
        }
        if (nums[k] == target) r[0] = k;
        i = 0;
        j = nums.size()-1;
        k = (i+j)/2;
        while (i<j) {
            if (nums[k] > target) {
                j = k-1;
            } else {
                i = k;
            }
            k = (i+j+1)/2;
        }
        if (k >= 0 && nums[k] == target) r[1] = k;
        return r;
    }
};

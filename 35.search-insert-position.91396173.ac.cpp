/*
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position
 *
 * Easy (39.43%)
 * Total Accepted:    168737
 * Total Submissions: 427912
 * Testcase Example:  '[1]\n0'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * 
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target > nums.back()) return nums.size();
        int i,j,k;
        i = 0;
        j = nums.size()-1;
        k = (i+j)/2;
        while(i < j) {
            if (nums[k] < target) {
                i = k+1;
            } else {
                j = k;
            }
            k = (i+j)/2;
        }
        return k;
    }
};

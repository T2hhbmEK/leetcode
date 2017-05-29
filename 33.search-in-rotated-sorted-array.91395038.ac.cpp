/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array
 *
 * Medium (32.12%)
 * Total Accepted:    165635
 * Total Submissions: 515618
 * Testcase Example:  '[]\n5'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        unsigned long long i,j,k,N;
        N = nums.size();
        if (N <= 0) return -1;
        k = 0;
        if (nums.back() < nums.front()) {
            i = 0;
            j = nums.size()-1;
            k = (i+j)/2;
            while (i < j) {
                if (nums[k] > nums[k+1]) {
                    break;
                }
                if (nums[k] >= nums[i]) {
                    i = k+1;
                } else {
                    j = k;
                }
                k = (i+j)/2;
            }
            k = k+1;
        }
        i = k;
        j = k+nums.size()-1;
        k = (i+j)/2;
        while (i<j) {
            if (target > nums[k%nums.size()]) {
                i = k+1;
            } else {
                j = k;
            }
            k = (i+j)/2;
        }
        if (k>=i && nums[k%nums.size()] == target) return k%nums.size();
        return -1;
    }
};

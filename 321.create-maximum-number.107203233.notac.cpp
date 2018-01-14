/*
 * [321] Create Maximum Number
 *
 * https://leetcode.com/problems/create-maximum-number/description/
 *
 * algorithms
 * Hard (24.78%)
 * Total Accepted:    21.6K
 * Total Submissions: 87.4K
 * Testcase Example:  '[3,4,6,5]\n[9,1,2,5,8,3]\n5'
 *
 * 
 * ⁠   Given two arrays of length m and n with digits 0-9 representing two
 * numbers.
 * ⁠   Create the maximum number of length k  from digits of the two. The
 * relative order of the digits
 * ⁠   from the same array must be preserved. Return an array of the k digits.
 * You should try to optimize your time and space complexity.
 * 
 * 
 * 
 * ⁠   Example 1:
 * 
 * 
 * ⁠   nums1 = [3, 4, 6, 5]
 * ⁠   nums2 = [9, 1, 2, 5, 8, 3]
 * ⁠   k = 5
 * ⁠   return [9, 8, 6, 5, 3]
 * 
 * 
 * ⁠   Example 2:
 * 
 * 
 * ⁠   nums1 = [6, 7]
 * ⁠   nums2 = [6, 0, 4]
 * ⁠   k = 5
 * ⁠   return [6, 7, 6, 0, 4]
 * 
 * 
 * ⁠   Example 3:
 * 
 * 
 * ⁠   nums1 = [3, 9]
 * ⁠   nums2 = [8, 9]
 * ⁠   k = 3
 * ⁠   return [9, 8, 9]
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> nums1k = maxNumberAll(nums1,k);
        vector<vector<int>> nums2k = maxNumberAll(nums2,k);
        vector<int> r;
        for (int i = max(0, k-(int)nums2.size()); i <= min(k, (int)nums1.size()); i++){
            r = max(r, maxNumber(nums1k[nums1k.size()-1-i],nums2k[nums2k.size()-1-(k-i)]));
        }
        return r;
    }
    vector<vector<int>> maxNumberAll(vector<int> nums, int k) {
        vector<vector<int>> r;
        int i = 0;
        while (!nums.empty()) {
            r.push_back(nums);
            if (r.size() > k) {
                r.erase(r.begin());
            }
            while(i+1 < nums.size() && nums[i] >= nums[i+1]) {
                i++;
            }
            if (i >= nums.size()) {
                i = (int)nums.size()-1;
            }
            nums.erase(nums.begin()+i);
            if (i > 0) {
                i--;
            }
        }
        r.push_back({});
        return r;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<int> r;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                r.push_back(nums1[i]);
                i++;
            } else if (nums1[i] < nums2[i]) {
                r.push_back(nums2[j]);
                j++;
            } else {
                int k = 0;
                while (i+k < nums1.size() && j+k < nums2.size() && nums1[i+k] == nums2[j+k]) {
                    k++;
                }
                if (i+k >= nums1.size()) {
                    r.push_back(nums2[j]);
                    j++;
                } else if (j+k >= nums2.size()) {
                    r.push_back(nums1[i]);
                    i++;
                } else if (nums1[i+k] < nums2[j+k]) {
                    r.push_back(nums2[j]);
                    j++;
                } else {
                    r.push_back(nums1[i]);
                    i++;
                }
            }
        }
        while (i < nums1.size()) {
            r.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) {
            r.push_back(nums2[j]);
            j++;
        }
        return r;
    }
};


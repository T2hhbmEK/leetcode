/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum
 *
 * Easy (33.04%)
 * Total Accepted:    505359
 * Total Submissions: 1529675
 * Testcase Example:  '[3,2,4]\n6'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> r;
        for (int i = 0; i < nums.size(); i++) {
            int numToFind = target - nums[i];
            if (map.find(numToFind) != map.end()) {
                r.push_back(map[numToFind]);
                r.push_back(i);
                return r;
            }
            map[nums[i]] = i;
        }
        return r;
    }
};

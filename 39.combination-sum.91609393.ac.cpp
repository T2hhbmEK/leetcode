/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum
 *
 * Medium (37.48%)
 * Total Accepted:    153127
 * Total Submissions: 408557
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 
 * Given a set of candidate numbers (C) (without duplicates) and a target
 * number (T), find all unique combinations in C where the candidate numbers
 * sums to T. 
 * 
 * 
 * The same repeated number may be chosen from C unlimited number of times.
 * 
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * 
 * [
 * ⁠ [7],
 * ⁠ [2, 2, 3]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        trace.clear();
        for(auto&& a:result) {
            a.clear();
        }
        result.clear();
        combinationSum(candidates, target, candidates.size());
        return result;
    }
    
private:
    vector<int> trace;
    vector<vector<int>> result;
    
    void combinationSum(vector<int>& candidates, int target, int length) {
        if (target == 0) {
            result.push_back(trace);
            return;
        }
        if (target > 0) {
            for (int i = length-1; i >= 0; i--) {
                trace.push_back(candidates[i]);
                combinationSum(candidates, target-candidates[i], i+1);
                trace.pop_back();
            }
        }
        return;
    }
};

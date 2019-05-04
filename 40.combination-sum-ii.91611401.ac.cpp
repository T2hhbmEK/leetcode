/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii
 *
 * Medium (32.72%)
 * Total Accepted:    110276
 * Total Submissions: 337021
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 
 * Given a collection of candidate numbers (C) and a target number (T), find
 * all unique combinations in C where the candidate numbers sums to T.
 * 
 * 
 * Each number in C may only be used once in the combination.
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
 * A solution set is: 
 * 
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        trace.clear();
        for(auto&& a:result) {
            a.clear();
        }
        result.clear();
        sort(candidates.begin(),candidates.end());
        combinationSum2(candidates, target, candidates.size());
        return result;
    }
private:
    vector<int> trace_i;
    vector<int> trace;
    vector<vector<int>> result;
    
    void combinationSum2(vector<int>& candidates, int target, int length) {
        if (target == 0) {
            result.push_back(trace);
            return;
        }
        if (target > 0) {
            for (int i = length-1; i >= 0; i--) {
                if (i < candidates.size()-1 && candidates[i] == candidates[i+1] && (!trace_i.size() || trace_i.back()!= i+1)) {
                    continue;
                }
                trace_i.push_back(i);
                trace.push_back(candidates[i]);
                combinationSum2(candidates, target-candidates[i], i);
                trace.pop_back();
                trace_i.pop_back();
            }
        }
    }
};

/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (35.45%)
 * Total Accepted:    336.7K
 * Total Submissions: 949.8K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */
/*
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals
 *
 * Medium (29.38%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 *
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
 public:
  vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> result;
    sort(intervals.begin(), intervals.end(),
         [](Interval a, Interval b) { return a.start < b.start; });
    for (auto pos = intervals.begin(); pos < intervals.end(); pos++) {
      while (pos < intervals.end() - 1 && pos->end >= (pos + 1)->start) {
        pos->end = pos->end > (pos + 1)->end ? pos->end : (pos + 1)->end;
        swap(*pos, *(pos + 1));
        pos++;
      }
      result.push_back(*pos);
    }
    return result;
  }
};


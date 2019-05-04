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

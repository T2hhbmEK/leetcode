/*
 * [275] H-Index II
 *
 * https://leetcode.com/problems/h-index-ii/description/
 *
 * algorithms
 * Medium (34.91%)
 * Total Accepted:    62.1K
 * Total Submissions: 177.9K
 * Testcase Example:  '[]'
 *
 *
 * Follow up for H-Index: What if the citations array is sorted in ascending
 * order? Could you optimize your algorithm?
 *
 */
class Solution {
public:
  int hIndex(vector<int> &citations) {
    int h_max = citations.size();
    vector<int> counter(h_max + 1, 0);
    for (auto &c : citations) {
      if (c >= h_max) {
        counter[h_max]++;
      } else {
        counter[c]++;
      }
    }
    if (counter[h_max] >= h_max) {
      return h_max;
    }
    for (int i = h_max - 1; i >= 0; --i) {
      counter[i] += counter[i + 1];
      if (counter[i] >= i) {
        return i;
      }
    }
    return 0;
  }
};

/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (30.22%)
 * Total Accepted:    227.1K
 * Total Submissions: 751.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
/*
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix
 *
 * Medium (25.44%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 *
 *
 *
 * For example,
 * Given the following matrix:
 *
 *
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 *
 *
 * You should return [1,2,3,6,9,8,7,4,5].
 *
 */
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result = {};
    int rows = matrix.size();
    int cols = 0;
    if (rows > 0) {
      cols = matrix[0].size();
    }
    return spiralOrder(matrix, 0, cols - 1, rows - 1, 0, result);
  }
  vector<int> spiralOrder(vector<vector<int>>& matrix, int top, int right,
                          int bottom, int left, vector<int>& result) {
    // nothing
    if (top > bottom || left > right) {
      return result;
    }
    // one row
    if (top == bottom) {
      for (int i = top, j = left; j <= right; j++) {
        result.push_back(matrix[i][j]);
      }
      return result;
    }
    // one col
    if (left == right) {
      for (int i = top, j = left; i <= bottom; i++) {
        result.push_back(matrix[i][j]);
      }
      return result;
    }
    // top row
    for (int i = top, j = left; j < right; j++) {
      result.push_back(matrix[i][j]);
    }
    // right col
    for (int i = top, j = right; i < bottom; i++) {
      result.push_back(matrix[i][j]);
    }
    // bottom row
    for (int i = bottom, j = right; j > left; j--) {
      result.push_back(matrix[i][j]);
    }
    // left col
    for (int i = bottom, j = left; i > top; i--) {
      result.push_back(matrix[i][j]);
    }
    return spiralOrder(matrix, ++top, --right, --bottom, ++left, result);
  }
};


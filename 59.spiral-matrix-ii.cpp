/*
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii
 *
 * Medium (38.97%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '0'
 *
 * Given an integer n, generate a square matrix filled with elements from 1 to
 * n2 in spiral order.
 *
 *
 * For example,
 * Given n = 3,
 *
 * You should return the following matrix:
 *
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 *
 */
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    int x = 1;
    generateMatrix(result, 0, n - 1, n - 1, 0, x);
    return result;
  }
  void generateMatrix(vector<vector<int>>& matrix, int top, int right,
                      int bottom, int left, int x) {
    // nothing
    if (top > bottom || left > right) {
      return;
    }
    // one row
    if (top == bottom) {
      for (int i = top, j = left; j <= right; j++) {
        matrix[i][j] = x++;
      }
      return;
    }
    // one col
    if (left == right) {
      for (int i = top, j = left; i <= bottom; i++) {
        matrix[i][j] = x++;
      }
      return;
    }
    // top row
    for (int i = top, j = left; j < right; j++) {
      matrix[i][j] = x++;
    }
    // right col
    for (int i = top, j = right; i < bottom; i++) {
      matrix[i][j] = x++;
    }
    // bottom row
    for (int i = bottom, j = right; j > left; j--) {
      matrix[i][j] = x++;
    }
    // left col
    for (int i = bottom, j = left; i > top; i--) {
      matrix[i][j] = x++;
    }
    generateMatrix(matrix, ++top, --right, --bottom, ++left, x);
  }
};

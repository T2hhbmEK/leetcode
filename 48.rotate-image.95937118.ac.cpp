/*
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image
 *
 * Medium (38.05%)
 * Total Accepted:    109722
 * Total Submissions: 288372
 * Testcase Example:  '[[1]]'
 *
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Follow up:
 * Could you do this in-place?
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // (i, j) -> (j, n-1-i)
        int n = matrix.size();
        for (int i = 0; i <= (n-1)/2; i++) {
            for (int j = 0; j < n/2; j++) {
                int x = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = x;
            }
        }
        return;
    }
};

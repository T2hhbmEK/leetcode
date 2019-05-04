/*
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku
 *
 * Medium (35.02%)
 * Total Accepted:    115836
 * Total Submissions: 330743
 * Testcase Example:  '[".87654321","2........","3........","4........","5........","6........","7........","8........","9........"]'
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 * 
 * 
 * 
 * A partially filled sudoku which is valid.
 * 
 * 
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only
 * the filled cells need to be validated.
 * 
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> pool(9,0);
        // rows;
        for (int i = 0; i < board.size(); i++) {
            pool.assign(9,0);
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    pool[board[i][j]-'1']++;
                    if (pool[board[i][j]-'1'] > 1) return false;
                }
            }
        }
        // cols;
        for (int i = 0; i < board.size(); i++) {
            pool.assign(9,0);
            for (int j = 0; j < board[i].size(); j++) {
                if (board[j][i] != '.') {
                    pool[board[j][i]-'1']++;
                    if (pool[board[j][i]-'1'] > 1) return false;
                }
            }
        }
        // grids;
        for (int i = 0; i < board.size(); i+=3) {
            for (int j = 0; j < board.size(); j+=3) {
                pool.assign(9,0);
                for (int k = i; k < i+3; k++) {
                    for (int l = j; l < j+3; l++) {
                        if (board[k][l] != '.') {
                            pool[board[k][l]-'1']++;
                            if (pool[board[k][l]-'1'] > 1) return false;
                        }
                    }
                }
            }
        }
        // Valid
        return true;
    }
};

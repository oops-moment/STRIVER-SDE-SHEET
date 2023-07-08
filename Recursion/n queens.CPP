class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        int tempR = row;
        int tempC = col;

        // Check left columns in the same row
        while (col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            col--;
        }

        // Check upper diagonal
        row = tempR;
        col = tempC;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }

        // Check lower diagonal
        row = tempR;
        col = tempC;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string>& board, vector<vector<string>>& finalAns, int n) {
        if (col == n) {
            // If we reached the last column, it means a valid configuration is found
            finalAns.push_back(board);
            return;
        }

        // Try to place a queen in the current column
        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col, n)) {
                // If it's safe to place a queen, make the move
                board[row][col] = 'Q';

                // Recursively solve for the next column
                solve(col + 1, board, finalAns, n);

                // Undo the move for backtracking
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; // Store the final answers
        string temp(n, '.');
        vector<string> board(n, temp);

        // Start solving from the first column
        solve(0, board, ans, n);

        return ans;
    }
};

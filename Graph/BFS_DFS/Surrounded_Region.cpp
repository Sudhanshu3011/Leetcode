// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

// Example 1:

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& visi,
             vector<vector<char>>& board, int movrow[], int movcol[]) {
        visi[i][j] = 1;
        int n = board.size();
        int m = board[0].size();

        for (int k = 0; k < 4; k++) {
            int nrow = i + movrow[k];
            int ncol = j + movcol[k];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !visi[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, visi, board, movrow, movcol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int movrow[] = {-1, 0, 1, 0};
        int movcol[] = {0, 1, 0, -1};

        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();

        vector<vector<int>> visi(n, vector<int>(m, 0));

        // Traverse first and last row
        for (int j = 0; j < m; j++) {
            if (!visi[0][j] && board[0][j] == 'O') {
                dfs(0, j, visi, board, movrow, movcol);
            }
            if (!visi[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, visi, board, movrow, movcol);
            }
        }

        // Traverse first and last column
        for (int i = 0; i < n; i++) {
            if (!visi[i][0] && board[i][0] == 'O') {
                dfs(i, 0, visi, board, movrow, movcol);
            }
            if (!visi[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, visi, board, movrow, movcol);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visi[i][j] == 0 && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

// Example 1:

// Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3
// Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.


class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int movrow[] = {-1, 0, 1, 0};
        int movcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (!vis[i][j] && grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        while (!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nrow = row + movrow[k];
                int ncol = col + movcol[k];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1) {

                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        int enclaves = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
};
//DFS way of approach

class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>
    grid,
             int movrow[], int movcol[]) {
        vis[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for (int k = 0; k < 4; k++) {
            int nrow = i + movrow[k];
            int ncol = j + movcol[k];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, grid, movrow, movcol);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int movrow[] = {-1, 0, 1, 0};
        int movcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {

            if (!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, vis, grid, movrow, movcol);
            }
            if (!vis[n - 1][j] && grid[n - 1][j] == 1) {
                dfs(n - 1, j, vis, grid, movrow, movcol);
            }
        }
        for (int i = 0; i < n; i++) {

            if (!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, vis, grid, movrow, movcol);
            }
            if (!vis[i][m - 1] && grid[i][m - 1] == 1) {
                dfs(i, m - 1, vis, grid, movrow, movcol);
            }
        }

        int enclaves = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << vis[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
};
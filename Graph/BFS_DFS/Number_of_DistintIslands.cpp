// Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

// Example 1:

// Input:
// grid[][] = {{1, 1, 0, 0, 0},
//             {1, 1, 0, 0, 0},
//             {0, 0, 0, 1, 1},
//             {0, 0, 0, 1, 1}}
// Output:
// 1
// Explanation:
// grid[][] = {{1, 1, 0, 0, 0}, 
//             {1, 1, 0, 0, 0}, 
//             {0, 0, 0, 1, 1}, 
//             {0, 0, 0, 1, 1}}
// Same colored islands are equal.
// We have 2 equal islands, so we 
// have only 1 distinct island.

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &v, int row_, int col_) {
        vis[i][j] = 1;
        v.push_back({i - row_, j - col_});  
        
        int n = grid.size();
        int m = grid[0].size();

        int movrow[] = {-1, 0, 1, 0};
        int movcol[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int rows = i + movrow[k];
            int col = j + movcol[k];

            if (rows >= 0 && rows < n && col >= 0 && col < m && !vis[rows][col] && grid[rows][col] == 1) {
                dfs(rows, col, vis, grid, v, row_, col_);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> shapes;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> v;
                    dfs(i, j, vis, grid, v, i, j);
                    shapes.insert(v);
                }
            }
        }

        return shapes.size();
    }
};

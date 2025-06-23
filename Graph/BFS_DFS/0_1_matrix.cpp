// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two cells sharing a common edge is 1.

 
// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> min_dis(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        int row_[] = {1, 0, -1, 0};
        int col_[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            min_dis[r][c] = dis;

            for (int i = 0; i < 4; i++) {
                int n_row = r + row_[i];
                int n_col = c + col_[i];

                if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m &&
                    visited[n_row][n_col]==0) {
                    q.push({{n_row, n_col}, dis + 1});
                    visited[n_row][n_col] = true;
                }
            }
        }

        return min_dis;
    }
};

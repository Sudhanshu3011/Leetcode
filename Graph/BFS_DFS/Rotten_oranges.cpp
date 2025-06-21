// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        if (grid.empty() == 1)
            return 0;
        int n = grid.size(), m = grid[0].size(), cnt = 0, oranges = 0, days = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] != 0)
                {
                    oranges++;
                    if (grid[i][j] == 2)
                    {
                        q.push({i, j});
                    }
                }
            }
        }

        int row[] = {1, 0, -1, 0};
        int col[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int k = q.size();
            cnt += k;

            while (k > 0)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {

                    int n_row = x + row[i];
                    int n_col = y + col[i];

                    if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m &&
                        grid[n_row][n_col] == 1)
                    {
                        grid[n_row][n_col] = 2;
                        q.push({n_row, n_col});
                    }
                }
                k--;
            }
            if (!q.empty())
                days++;
        }

        return oranges == cnt ? days : -1;
    }
};
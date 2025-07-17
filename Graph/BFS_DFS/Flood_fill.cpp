// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill:

// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.

// Example 1:

// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

// Output: [[2,2,2],[2,2,0],[2,0,1]]

class Solution
{
public:
    void bfs(int row, int col, int inicolor, int set_color, vector<vector<int>> &image, vector<vector<int>> &ans)
    {

        int n = image.size();
        int m = image[0].size();
        int trav_row[] = {1, 0, -1, 0};
        int trav_col[] = {0, 1, 0, -1};

        ans[row][col] = set_color;
        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty())
        {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int n_row = r + trav_row[i];
                int n_col = c + trav_col[i];

                if (n_row < n && n_row >= 0 && n_col < m && n_col >= 0 && image[n_row][n_col] == inicolor && ans[n_row][n_col] != set_color)
                {
                    ans[n_row][n_col] = set_color;
                    q.push({n_row, n_col});
                }
            }
        }

        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        vector<vector<int>> ans = image;
        int inicolor = image[sr][sc];
        if (inicolor == color)
            return ans;

        bfs(sr, sc, inicolor, color, image, ans);

        return ans;
    }
};
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                cnt++;
                dfs(i, adj, visited);
            }
        }

        return cnt;
    }
};

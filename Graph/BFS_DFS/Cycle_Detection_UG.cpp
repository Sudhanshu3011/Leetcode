// Problem statement
// You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.

// Your task is to find if the graph contains a cycle or not.

// A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.
// Note:

// 1. There are no parallel edges between two vertices.

// 2. There are no self-loops(an edge connecting the vertex to itself) in the graph.

// 3. The graph can be disconnected.
// For Example :

// Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
// Output: Yes

// Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and vertex 1 and 3. So, there exists a cycle in the graph.

#include <vector>
#include <queue>
#include <utility>
using namespace std;

bool cycle(int node, vector<int> adj[], vector<int> &visited)
{
    visited[node] = 1;
    queue<pair<int, int>> q;
    q.push({node, -1});

    while (!q.empty())
    {
        int nod = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjnode : adj[nod])
        {
            if (!visited[adjnode])
            {
                visited[adjnode] = 1;
                q.push({adjnode, nod});
            }
            else if (adjnode != parent)
            {
                return true;
            }
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    vector<int> adj[n + 1];
    vector<int> visited(n + 1, 0);

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (cycle(i, adj, visited))
            {
                return "Yes";
            }
        }
    }

    return "No";
}

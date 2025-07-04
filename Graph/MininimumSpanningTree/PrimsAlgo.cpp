// Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

// Input:
// 3 3
// 0 1 5
// 1 2 3
// 0 2 1
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<int> vis(V, 0);
        vector<pair<int, int>> MST;
        int spt = 0;

        pq.push({0, {0, -1}});

        while (!pq.empty())
        {

            auto it = pq.top();
            pq.pop();

            int dist = it.first, node = it.second.first, parent = it.second.second;

            if (vis[node] == 1)
                continue;
            vis[node] = 1;
            spt += dist;
            if (parent != -1)
                MST.push_back({parent, node});

            for (auto &itr : adj[node])
            {

                int adjnode = itr[0];
                int adjdist = itr[1];

                if (!vis[adjnode])
                    pq.push({adjdist, {adjnode, node}});
            }
        }
        return spt;
    }
};
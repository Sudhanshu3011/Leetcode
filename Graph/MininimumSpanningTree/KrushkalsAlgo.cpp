// Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

// Input:
// 3 3
// 0 1 5
// 1 2 3
// 0 2 1
class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUpar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void Union(int u, int v)
    {
        int u_upar = findUpar(u);
        int v_upar = findUpar(v);

        if (u_upar == v_upar)
            return;

        if (rank[u_upar] < rank[v_upar])
        {
            parent[u_upar] = v_upar;
        }
        else if (rank[u_upar] > rank[v_upar])
        {
            parent[v_upar] = u_upar;
        }
        else
        {
            parent[v_upar] = u_upar;
            rank[u_upar]++;
        }
    }
};
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here

        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < V; i++)
        {
            for (auto &it : adj[i])
            {

                int u = i, v = it[0], wt = it[1];

                edges.push_back({wt, {u, v}});
            }
        }

        sort(edges.begin(), edges.end());

        int mst = 0;

        DisjointSet ds(V);

        for (auto &itr : edges)
        {
            int wt = itr.first, node = itr.second.first, adj_node = itr.second.second;

            if (ds.findUpar(node) != ds.findUpar(adj_node))
            {
                mst += wt;
                ds.Union(node, adj_node);
            }
        }
        return mst;
    }
};
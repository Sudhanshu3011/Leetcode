// Min Cost to Connect All Points

// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

// Example 1:

// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation:

// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.
// Example 2:

// Input: points = [[3,12],[-2,5],[-4,1]]
// Output: 18

// Implementation Logic
// Here the point of 2D graph is given and we need to connect them all in minimum value.
// First we find the distance of the each point to the other , placing it in the edges where
// {wt , i, j} thr i=[x,y] and j=[a,b] ,the two points on the graph implement the sort on
//  the edge that the minimum distace always on top .Then using the dsu logic connect two
//  disconnected point with minimum values.

class Disjoint
{

    vector<int> parent, siz;

public:
    Disjoint(int n)
    {
        parent.resize(n + 1);
        siz.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int fUpar(int node)
    {

        if (parent[node] == node)
            return node;

        return parent[node] = fUpar(parent[node]);
    }

    void Union(int u, int v)
    {

        int upar = fUpar(u);
        int vpar = fUpar(v);

        if (upar == vpar)
            return;
        if (siz[upar] < siz[vpar])
        {
            parent[upar] = vpar;
            siz[vpar] += siz[upar];
        }
        else
        {
            parent[vpar] = upar;
            siz[upar] += siz[vpar];
        }
    }
};
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {

        vector<pair<int, pair<int, int>>> edges;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {

            int u_x = points[i][0];
            int u_y = points[i][1];

            for (int j = i + 1; j < n; j++)
            {

                int v_x = points[j][0];
                int v_y = points[j][1];

                int dist = abs(u_x - v_x) + abs(u_y - v_y);

                edges.push_back({dist, {i, j}});
            }
        }

        sort(edges.begin(), edges.end());

        int mst = 0;

        Disjoint ds(n);

        for (auto &itr : edges)
        {

            int wt = itr.first, node = itr.second.first,
                adj_node = itr.second.second;

            if (ds.fUpar(node) != ds.fUpar(adj_node))
            {

                mst += wt;
                ds.Union(node, adj_node);
            }
        }

        return mst;
    }
};
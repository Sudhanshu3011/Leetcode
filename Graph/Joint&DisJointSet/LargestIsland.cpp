//  Making A Large Island
// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

// Return the size of the largest island in grid after applying this operation.

// An island is a 4-directionally connected group of 1s.

// Example 1:

// Input: grid = [[1,0],[0,1]]
// Output: 3
// Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
// Example 2:

// Input: grid = [[1,1],[1,0]]
// Output: 4
// Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
// Example 3:

// Implementation Logic:

// here the array is gievn so consinder each element array as a single node to perform
// the DSU logic of UnionBySize
// Now trasverse through the array and if we get 1,  then move in four direction
// and check if the new upcoming row and column is in the range and if so then ,
// it must be 1 ,proceed from here to join the the previos grid[i][j] and the
//  grid[nr][nc] considering them as two nodes
// Go agin through the grid and check for the 0, if in its neighbour we get 1 ,
// insert the ultimate parent into the set to by getting rid of the multiple time
// getting same group of island, after seeing all the four direction ,go inside the
// set and fetch the size of node in the set sum it to get the new formed island ,
// return the largest formed such island
// but still there is a edge case if the grid is all one then we have to deep dive
// in the disjoint set node to get the ulimate parent size
class Disjoint
{

public:
    vector<int> parent, siz;

    Disjoint(int n)
    {

        siz.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUpar(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findUpar(parent[node]);
    }

    void Unionbysize(int u, int v)
    {
        int upar_u = findUpar(u);
        int upar_v = findUpar(v);

        if (upar_u == upar_v)
            return;
        if (siz[upar_v] < siz[upar_u])
        {

            parent[upar_v] = upar_u;
            siz[upar_u] += siz[upar_v];
        }
        else
        {

            parent[upar_u] = upar_v;
            siz[upar_v] += siz[upar_u];
        }
    }
};
class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {

        int n = grid.size();

        Disjoint ds(n * n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int node = i * n + j;
                if (grid[i][j] == 0)
                    continue;

                int mvr[] = {-1, 0, 1, 0};
                int mvc[] = {0, -1, 0, 1};

                for (int k = 0; k < 4; k++)
                {

                    int nr = i + mvr[k];
                    int nc = j + mvc[k];

                    if ((nr >= 0 && nr < n && nc >= 0 && nc < n) &&
                        grid[nr][nc] == 1)
                    {

                        int adjnode = nr * n + nc;

                        ds.Unionbysize(node, adjnode);
                    }
                }
            }
        }

        int largeisland = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    set<int> st;
                    int mvr[] = {-1, 0, 1, 0};
                    int mvc[] = {0, -1, 0, 1};

                    for (int k = 0; k < 4; k++)
                    {

                        int nr = i + mvr[k];
                        int nc = j + mvc[k];

                        if ((nr >= 0 && nr < n && nc >= 0 && nc < n) &&
                            grid[nr][nc] == 1)
                        {

                            int adjnode = nr * n + nc;
                            st.insert(ds.findUpar(adjnode));
                        }
                    }
                    int mergeisland = 1;
                    for (int it : st)
                    {
                        mergeisland += ds.siz[it];
                    }

                    largeisland = max(largeisland, mergeisland);
                }
            }
        }

        for (int nodes = 0; nodes < n * n; nodes++)
        {
            largeisland = max(largeisland, ds.siz[ds.findUpar(nodes)]);
        }

        return largeisland;
    }
};
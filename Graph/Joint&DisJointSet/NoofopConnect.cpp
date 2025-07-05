//  Number of Operations to Make Network Connected

// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

// Example 1:

// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

// Implementation Logic:-
// First we implementde the logic of the DSU(by Size) to connect the computer in the
// given question . After that we collectred the extra edges in the graph then finding
// number of the discnnected components in the given graph , we came to conclusion that
// the no of edges required to connect the disconnnected componemt is disconnectedComputer-1
// and if (disconnectedComputer-1) > than the extra edges then we can say that
// ans=disconnectedComputer-1 else the no of the edges required to connect the disconnected
// components is less there hense return -1.

class Disjoint
{

public:
    vector<int> parent, siz;
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
    int makeConnected(int n, vector<vector<int>> &connections)
    {

        Disjoint ds(n);
        int extraedge = 0;

        for (auto &it : connections)
        {

            int u = it[0], v = it[1];

            if (ds.fUpar(u) == ds.fUpar(v))
            {

                extraedge++;
            }
            else
            {
                ds.Union(u, v);
            }
        }

        int disconnectedcomp = 0;

        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                disconnectedcomp++;
        }

        int ans = disconnectedcomp - 1;

        if (extraedge >= ans)
            return ans;
        return -1;
    }
};

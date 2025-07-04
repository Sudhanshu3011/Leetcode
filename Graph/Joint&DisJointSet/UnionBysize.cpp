#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, siz;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        siz.resize(n + 1, 1);
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

        if (siz[u_upar] < siz[v_upar])
        {
            parent[u_upar] = v_upar;
            siz[v_upar] += siz[u_upar];
        }
        else
        {
            parent[v_upar] = u_upar;
            siz[u_upar] += siz[v_upar];
        }
    }
};

int main()
{
    DisjointSet ds(7);

    ds.Union(1, 2);
    ds.Union(2, 7);
    ds.Union(4, 5);
    ds.Union(4, 6);

    if (ds.findUpar(4) == ds.findUpar(1))
        cout << "Same\n";
    else
        cout << "Not Same\n";

    ds.Union(1, 4);

    if (ds.findUpar(4) == ds.findUpar(1))
        cout << "Same\n";
    else
        cout << "Not Same\n";

    return 0;
}

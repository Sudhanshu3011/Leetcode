#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra_path(vector<vector<int>> &vec, int vertices, int edges, int source, int destination) {
    vector<pair<int,int>> adj[vertices];

    
    for(auto &it : vec){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v, wt});
       
    }

    vector<int> dist(vertices, INT_MAX), parent(vertices);
    for(int i = 0; i < vertices; i++) parent[i] = i;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty()) {
        auto [wt, node] = pq.top();
        pq.pop();

        for(auto &it_ : adj[node]){
            int adjnode = it_.first;
            int adjwt = it_.second;

            if(wt + adjwt < dist[adjnode]) {
                dist[adjnode] = wt + adjwt;
                parent[adjnode] = node;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }


    vector<int> path;
    int node = destination;

    if (dist[node] == INT_MAX) return {}; 

    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());

    return path;
}

// Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

// Your task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
         vector<int> dist(V, 1e8);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto &it : edges) {
            int u = it[0], v = it[1], wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    //  Check for negative weight cycle
    for (auto &it : edges) {
        int u = it[0], v = it[1], wt = it[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return {-1}; 
        }
    }

    return dist;
    }
};

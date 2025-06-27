// Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
// Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

// Examples:

// Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<int> indegre(V,0),topo_sort ;
        vector<int> adj[V];
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            indegre[v]++;
            adj[u].push_back(v);
            
        }
        
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegre[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node]){
                indegre[it]--;
                if(indegre[it]==0){
                    q.push(it);
                }
            }
            
            topo_sort.push_back(node);
        }
        
        return topo_sort;
       
    }
};

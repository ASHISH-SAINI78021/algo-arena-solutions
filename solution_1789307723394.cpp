class Solution {
  public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, int parent){
        visited[node] = true;
        
        for (auto it : adj[node]){
            if (visited[it] == 0){
                if (dfs(it, adj, visited, node)){
                    return true;
                }
            }
            else if (parent != it) return true;
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++){
            if (visited[i] == 0){
                bool ans = dfs(i, adj, visited, -1);
                if (ans) return true;
            }
        }
        
        return false;
    }
};
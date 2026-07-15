class Solution {
  public:
    bool dfs(int node, int parent, vector<int> &visited, vector<vector<int>> &adj){
        visited[node] = 1;
        
        for (auto it : adj[node]){
            if (visited[it] == 0){
                if (dfs(it, node, visited, adj)) return true; 
            }
            else if (it != parent) return true;
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> visited(V, 0);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for (int i = 0; i < V; i++){
            if (visited[i] == 0){
                if(dfs(i, -1, visited, adj)) return true;
            }
        }
        
        
        return false;
    }
};
class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &ans){
        visited[node] = 1;
        ans.push_back(node);
        for (auto it : adj[node]){
            if (visited[it] == 0){
                dfs(it, adj, visited, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> ans;
        int n = adj.size();
        
        vector<int> visited(n + 1, 0);
        for (int i = 0; i < n; i++){
            if (visited[i] == 0){
                dfs(i, adj, visited, ans);
            }
        }
        
        return ans;
    }
};
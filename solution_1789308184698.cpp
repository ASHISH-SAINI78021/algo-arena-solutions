class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        int n = edges.size();
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for (int i = 0; i < n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        for (int i = 0; i < V; i++){
            for (auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++){
            if (indegree[i] == 0) q.push(i);
        }
        
        int count = 0;
        while (!q.empty()){
            auto front = q.front(); q.pop();
            count++;
            
            for (auto it : adj[front]){
                indegree[it]--;
                if (indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        bool isCycle = (count == V) ? false : true;
        
        return isCycle;
    }
};
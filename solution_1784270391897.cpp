class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        vector<int> dist(V,1e9);
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        pq.push({0, src});
        dist[src] = 0;
        
        while (!pq.empty()){
            auto front = pq.top(); pq.pop();
            int cost = front.first;
            int node = front.second;
            
            for (auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if (cost + wt < dist[v]){
                    dist[v] = cost + wt;
                    pq.push({cost + wt, v});
                }
            }
        }
        
        return dist;
    }
};
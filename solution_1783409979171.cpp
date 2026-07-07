class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, 1e9);
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, k});
        dist[k] = 0;

        vector<vector<T>> adj(n + 1);
        for (int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }

        int time = -1;
        
        while (!pq.empty()){
            auto front = pq.top(); pq.pop();
            int cost = front.first;
            int node = front.second;
            if (cost > dist[node]) continue ;
            time = max(time, cost);
            
            for (auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if (cost + wt < dist[v]){
                    dist[v] = cost + wt;
                    pq.push({cost + wt, v});
                }
            }
        }

        for (int i = 1; i <= n; i++){
            if (dist[i] == 1e9) return -1;
        }

        return time;
    }
};
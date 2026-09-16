class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0;i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v, wt});
        }

        int maxi = 0;
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<int> dist(n + 1, 1e9);
        pq.push({k, 0});
        dist[k] = 0;
        
        while (!pq.empty()){
            auto top = pq.top(); pq.pop();
            int cost = top.second;
            int node = top.first;

            for (auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if (cost + wt < dist[v]){
                    dist[v] = cost + wt;
                    pq.push({v, dist[v]});
                }
            }
        }

        for (int i = 1; i <= n; i++){
            if (dist[i] == 1e9) return -1;
            maxi = max(dist[i], maxi);
        }


        return maxi;
    }
};
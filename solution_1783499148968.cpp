class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n, 1e9);
        using T = pair<int, pair<int, int>>;
        queue<T> q;
        q.push({0, {0, src}});
        dist[src] = 0;

        for (int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});
        }

        while (!q.empty()){
            auto front = q.front(); q.pop();
            int stops = front.first;
            int cost = front.second.first;
            int u = front.second.second;

            if (stops > k) continue ;

            for (auto it : adj[u]){
                int v = it.first;
                int wt = it.second;
                if (cost + wt < dist[v] && stops <= k){
                    dist[v] = cost + wt;
                    q.push({stops + 1, {cost + wt, v}});
                }
            }
        }
        

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
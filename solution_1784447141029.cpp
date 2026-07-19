class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        vector<vector<pair<int,int>>> adj(n);
        using T = pair<int, pair<int, int>>;
        queue<T> q;

        for (int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});
        }

        q.push({0, {0, src}});
        dist[src] = 0;

        while (!q.empty()){
            auto front = q.front(); q.pop();
            int stops =  front.first;
            int cost = front.second.first;
            int node = front.second.second;

            if (stops > k) continue ;

            for (auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if (cost + wt < dist[v]){
                    dist[v] = cost + wt;
                    q.push({stops + 1, {cost + wt, v}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;

        using T = pair<int, pair<int,int>>;
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        pq.push({1, {0,0}});
        dist[0][0] = 1;

        int drow[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1};
        int dcol[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};
        
        while (!pq.empty()){
            auto front = pq.top(); pq.pop();
            int cost = front.first;
            int row = front.second.first;
            int col = front.second.second;

            for (int i = 0; i < 8; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0){
                    if (cost + 1 < dist[nrow][ncol]){
                        pq.push({cost + 1, {nrow, ncol}});
                        dist[nrow][ncol] = cost + 1;
                    }
                }
            }
        }

        int ans = dist[n - 1][m - 1];
        return ans == 1e9 ? -1 : ans;
    }
};
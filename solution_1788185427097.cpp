class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[n - 1][m - 1] == 1 || grid[0][0] == 1) return -1;
        using T = pair<int, pair<int, int>>;
        queue<T> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        q.push({1, {0,0}});
        dist[0][0] = 1;

        int drow[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1};
        int dcol[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};

        while (!q.empty()){
            auto front = q.front(); q.pop();
            int cost = front.first;
            int row = front.second.first;
            int col = front.second.second;

            for (int i = 0; i < 8; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0){
                    if (cost + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = cost + 1;
                        q.push({cost  + 1, {nrow, ncol}});
                    }
                }
            }
        }

        return dist[n - 1][m - 1] == 1e9 ? -1 : dist[n - 1][m - 1];
    }
};
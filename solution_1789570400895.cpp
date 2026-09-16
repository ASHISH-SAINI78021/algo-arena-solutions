class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        using T = pair<int, pair<int, int>>;
        queue<T> q;

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        vector<vector<int>> dist(n, vector<int> (n, 1e9));
        q.push({1, {0,0}});
        dist[0][0] = 1;

        int drow[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1};
        int dcol[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};
        while (!q.empty()){
            auto front = q.front(); q.pop();
            int cost = front.first;
            int row = front.second.first;
            int col = front.second.second;

            if (row == n - 1 && col == n - 1) return dist[row][col];

            for (int i = 0; i < 8; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0){
                    if (cost + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = cost + 1;
                        q.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }



        int ans = dist[n - 1][n - 1];
        return (ans == 1e9) ? -1 : ans;
    }
};
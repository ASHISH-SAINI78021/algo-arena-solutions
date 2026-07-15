class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        int n = mat.size();
        int m = mat[0].size();

        using T = pair<int, pair<int,int>>;
        queue<T> q;
        vector<vector<int>> dist(n, vector<int>(m,-1));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mat[i][j] == 0){
                    q.push({0, {i,j}});
                    dist[i][j] = 0;
                }
            }
        }

        int arr[4][2] = {
            {-1,0}, {0,1}, {1,0}, {0,-1}
        };
        while (!q.empty()){
            auto front = q.front(); q.pop();
            int cost = front.first;
            int row = front.second.first;
            int col = front.second.second;

            for (int i = 0; i < 4; i++){
                int nrow = row + arr[i][0];
                int ncol = col + arr[i][1];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 1 && dist[nrow][ncol] == -1){
                    q.push({cost + 1, {nrow, ncol}});
                    dist[nrow][ncol] = cost + 1;
                }
            }

        }

        return dist;
    }
};











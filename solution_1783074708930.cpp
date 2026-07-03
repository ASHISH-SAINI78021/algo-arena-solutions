class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int n = image.size();
        int m = image[0].size();
        using T = pair<int,int>;
        queue<T> q;
        q.push({sr, sc});
        vector<vector<int>> visited(n, vector<int>(m,0));
        visited[sr][sc] = 1;
        int initialColor = image[sr][sc];
        int arr[4][2] = {
            {-1,0}, {0,1}, {1,0}, {0,-1}
        };

        while (!q.empty()){
            auto front = q.front(); q.pop();
            int row = front.first;
            int col = front.second;

            ans[row][col] = color;
            for (int i = 0; i < 4; i++){
                int nrow = row + arr[i][0];
                int ncol = col + arr[i][1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initialColor && visited[nrow][ncol] == 0){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }

        return ans;
    }
};
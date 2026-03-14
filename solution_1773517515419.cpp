class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited, int arr[4][2]){
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;

        for (int i = 0; i < 4; i++){
            int nrow = row + arr[i][0];
            int ncol = col + arr[i][1];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, grid, visited, arr);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int arr[4][2] = {
            {-1,0}, {0,1}, {1,0}, {0,-1}
        };
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1' && visited[i][j] == 0){
                    dfs(i, j, grid, visited, arr);
                    count++;
                }
            }
        }

        return count;
    }
};
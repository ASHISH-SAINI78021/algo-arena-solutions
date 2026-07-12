class Solution {
public:
    int solve(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if (n < 0 || m < 0) return 1e9;
        if (n == 0 && m == 0) return grid[0][0];
        if (dp[n][m] != -1) return dp[n][m];

        int ans1 = solve(n - 1, m, grid, dp);
        int ans2 = solve(n, m - 1, grid, dp);

        return dp[n][m] = grid[n][m] + min(ans1, ans2);
    }
    int solve(int n, int m, vector<vector<int>> &grid){
        vector<vector<int>> dp(n, vector<int>(m,0));
        int sum = 0;
        for (int i = 0; i < m; i++){
            sum += grid[0][i];
            dp[0][i] = sum;
        }
        sum = 0;
        for (int i = 0; i < n; i++){
            sum += grid[i][0];
            dp[i][0] = sum;
        }

        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                int ans1 = dp[i - 1][j];
                int ans2 = dp[i][j - 1];

                dp[i][j] = grid[i][j] + min(ans1, ans2);
            }
        }

        return dp[n - 1][m - 1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        // int ans = solve(n - 1, m - 1, grid, dp);
        int ans = solve(n,m, grid);

        return ans;
    }
};
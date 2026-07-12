class Solution {
public:
    int solve(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp){
        if (n == 0 && m == 0) return 1;
        if (n < 0 || m < 0 || arr[n][m] == 1) return 0;
        if (dp[n][m] != -1) return dp[n][m];

        int ans1 = solve(n - 1, m, arr, dp);
        int ans2 = solve(n, m - 1, arr, dp);

        return dp[n][m] = ans1 + ans2;
    }
    int solve(int n, int m, vector<vector<int>> &arr){
        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++){
            if (arr[i][0] == 1) break;
            dp[i][0] = 1;
        }
        for (int i = 0; i < m; i++){
            if (arr[0][i] == 1) break;
            dp[0][i] = 1;
        }

        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if (arr[i][j] == 1){
                    dp[i][j] = 0;
                    continue ;
                }
                int ans1 = dp[i - 1][j];
                int ans2 = dp[i][j - 1];

                dp[i][j] = ans1 + ans2;
            }
        }

        return dp[n - 1][m - 1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        if (arr[n - 1][m - 1] == 1) return 0;
        if (arr[0][0] == 1) return 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // int ans = solve(n - 1, m - 1, arr, dp);
        int ans = solve(n, m, arr);

        return ans;
    }
};
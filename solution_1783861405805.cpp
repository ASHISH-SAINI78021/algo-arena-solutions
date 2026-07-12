class Solution {
public:
    int solve(int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &dp){
        int n = triangle.size();
        if (row == n - 1) return dp[row][col] = triangle[row][col];
        if (dp[row][col] != -1) return dp[row][col];

        int ans1 = solve(row + 1, col, triangle, dp);
        int ans2 = solve(row + 1, col + 1, triangle, dp);

        return dp[row][col] = triangle[row][col] + min(ans1, ans2);
    }
    int solve(vector<vector<int>> &triangle){
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < triangle[n - 1].size(); i++) dp[n - 1][i] = triangle[n - 1][i];

        for (int i = n - 2; i >= 0; i--){
            for (int j = triangle[i].size() - 1; j >= 0; j--){
                int ans1 = dp[i + 1][j];
                int ans2 = dp[i + 1][j + 1];

                dp[i][j] = triangle[i][j] + min(ans1, ans2);
            }
        }

        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int row = 0;
        int col = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // int ans = solve(row, col, triangle, dp);
        int ans = solve(triangle);

        return ans;
    }
};
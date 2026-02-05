class Solution {
public:
    int solve(int m, int n, vector<vector<long long>> &dp){
        if (n == 0 && m == 0) return 1;
        if (n < 0 || m < 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];

        long long ans1 = solve(m - 1, n, dp);
        long long ans2 = solve(m, n - 1, dp);

        return dp[m][n] = ans1 + ans2;
    }
    int uniquePaths(int m, int n) {
        if (n == 0 && m == 0) return 0;
        if (n == 1 && m == 1) return 1;
        vector<vector<long long>> dp(m + 1, vector<long long> (n + 1, -1));
        int ans = solve(m - 1, n - 1, dp);

        return ans;
    }
};
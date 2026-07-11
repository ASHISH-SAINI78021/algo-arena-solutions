class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dp){
        if (m == 0 && n == 0) return 1;
        if (m < 0 || n < 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];

        int ans1 = solve(m - 1, n, dp);
        int ans2 = solve(m, n - 1, dp);

        return dp[m][n] = ans1 + ans2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = solve(m - 1, n - 1, dp);

        return ans;
    }
};

// T.C -> O(2^(m + n))
// S.C -> O(m + n)
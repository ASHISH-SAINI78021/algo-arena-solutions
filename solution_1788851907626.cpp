class Solution {
public:
    int solve(int n, vector<int> &dp){
        // base case
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (dp[n] != -1) return dp[n];

        // solution for one case
        int ans1 = solve(n - 1, dp);
        int ans2 = solve(n - 2, dp);

        return dp[n] = ans1 + ans2;
    }
    int solve(int n){
        vector<int> dp(n + 1, 0);
        if (n == 1) return 1;
        if (n == 2) return 2;
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <= n; i++){
            int ans1 = dp[i - 1];
            int ans2 = dp[i - 2];
            dp[i] = ans1 + ans2;
        }

        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        int ans = solve(n);

        return ans;
    }
};
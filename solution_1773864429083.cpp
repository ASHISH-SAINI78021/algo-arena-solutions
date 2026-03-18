class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];

        int ans1 = solve(n - 1, dp);
        int ans2 = solve(n - 2, dp);
        
        return dp[n] = ans1 + ans2;
    }
    int climbStairs(int n){
        if (n == 1) return 1;
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
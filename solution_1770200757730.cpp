class Solution {
public:
    // int solve(int n, vector<int> &dp){
    //     if (n == 1) return 1;
    //     if (n == 2) return 2;
    //     if (dp[n] != -1) return dp[n];

    //     int ans1 = solve(n - 1, dp);
    //     int ans2 = solve(n - 2, dp);

    //     return dp[n] = ans1 + ans2;
    // }
    // int solve(int n){
    //     vector<int> dp(n + 1, 1);

    //     for (int i = 1; i <= n; i++){
    //         if (i == 1){
    //             dp[i] = 1;
    //             continue ;
    //         }
    //         if (i == 2){
    //             dp[i] = 2;
    //             continue ;
    //         }
    //         int ans1 = dp[i - 1];
    //         int ans2 = dp[i - 2];

    //         dp[i] = ans1 + ans2;
    //     }

    //     return dp[n];
    // }
    int solve(int n){
        if (n <= 2) return n;
        int prev1 = 1;
        int prev2 = 2;
        for (int i = 3; i <= n; i++){
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        int ans = solve(n);

        return ans;
    }
};
class Solution {
public:
    int solve(vector<int> &coins, int index, int amount, vector<vector<int>> &dp){
        // base case
        if (index >= coins.size() || amount < 0) return INT_MAX - 1;
        if (amount == 0) return 0;
        if (dp[index][amount] != -1) return dp[index][amount];

        // solution for one case
        int include = INT_MAX - 1;
        if (coins[index] <= amount) include = 1 + solve(coins, index, amount - coins[index], dp);
        int exclude = solve(coins, index + 1, amount, dp);

        return dp[index][amount] = min(include, exclude);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int index = 0;
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int ans = solve(coins, index, amount, dp);

        return (ans == INT_MAX - 1) ? -1 : ans;
    }
};
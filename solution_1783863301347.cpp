class Solution {
  public:
    int solve(vector<int> &val, vector<int> &wt, int index, int W, vector<vector<int>> &dp){
        int n = val.size();
        if (W <= 0) return 0;
        if (index >= n) return 0;
        if (dp[index][W] != -1) return dp[index][W];
        
        int include = 0;
        if (wt[index] <= W){
            include = val[index] + solve(val, wt, index + 1, W - wt[index], dp);
        }
        
        int exclude = solve(val, wt, index + 1, W, dp);
        
        return dp[index][W] = max(include, exclude);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        int index = 0;
        // int sum = accumulate(wt.begin(), wt.end());
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        int ans = solve(val, wt, index, W, dp);
        
        return ans;
    }
};
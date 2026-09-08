class Solution {
  public:
    int solve(vector<int> &height, int index, vector<int> &dp){
        int n = height.size();
        if (index >= n) return 1e9;
        if (index == n - 1) return 0;
        if (dp[index] != -1) return dp[index];
        
        int ans1 = abs(height[index + 1] - height[index]) + solve(height, index + 1, dp);
        int ans2 = abs(height[index + 2] - height[index]) + solve(height, index + 2, dp);
        
        return dp[index] = min(ans1, ans2);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        int index = 0;
        vector<int> dp(n + 1, -1);
        int ans = solve(height, index, dp);
        
        return ans;
    }
};
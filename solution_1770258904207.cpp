class Solution {
  public:
    // int solve(vector<int> &height, int index, vector<int> &dp){
    //     int n = height.size();
    //     if (index >= n - 1) return 0;
    //     if (dp[index] != -1) return dp[index];
        
    //     int jumpOne = abs(height[index] - height[index + 1]) + solve(height, index + 1, dp);
    //     int jumpTwo = INT_MAX;
    //     if (index + 2 < n){
    //         jumpTwo = abs(height[index] - height[index + 2]) + solve(height, index + 2, dp);
    //     }
        
    //     return dp[index] = min(jumpOne, jumpTwo);
    // }
    int solve(vector<int> &height, int index){
        int n = height.size();
        vector<int> dp(n + 1, 0);
        
        for (int i = n - 2; i >= 0; i--){
            int jumpOne = abs(height[i] - height[i + 1]) + dp[i + 1];
            int jumpTwo = INT_MAX;
            if (i + 2 < n){
                jumpTwo = abs(height[i] - height[i + 2]) + dp[i + 2];
            }
            
            dp[i] = min(jumpOne, jumpTwo);
        }
        
        return dp[0];
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        int index = 0;
        // vector<int> dp(n + 1, -1);
        int ans = solve(height, index);
        
        return ans;
    }
};




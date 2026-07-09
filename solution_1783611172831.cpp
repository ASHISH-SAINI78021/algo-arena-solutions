class Solution {
  public:
    int solve(vector<int> &arr, int index, vector<int> &dp){
        int n = arr.size();
        if (index == n - 1) return 0;
        if (index >= n) return 1e9;
        if (dp[index] != -1) return dp[index];
        
        int ans1 = 1e9;
        int ans2 = 1e9;
        if (index + 1 < n){
            ans1 = abs(arr[index + 1] - arr[index]) + solve(arr, index + 1, dp);
        }
        if (index + 2 < n){
            ans2 = abs(arr[index + 2] - arr[index]) + solve(arr, index + 2, dp);
        }
        
        return dp[index] = min(ans1, ans2);
    }
    int solve(vector<int> &arr){
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        dp[n - 1] = 0;
        
        for (int i = n - 2; i >= 0; i--){
            int ans1 = 1e9;
            int ans2 = 1e9;
            if (i + 1 < n) ans1 = abs(arr[i + 1] - arr[i]) + dp[i + 1];
            if (i + 2 < n) ans2 = abs(arr[i + 2] - arr[i]) + dp[i + 2];
            
            dp[i] = min(ans1, ans2);
        }
        
        return dp[0];
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        int index = 0;
        vector<int> dp(n + 1, -1);
        int ans = solve(height);
        
        return ans;
    }
};
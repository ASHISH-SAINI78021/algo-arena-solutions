class Solution {
  public:
    int solve(vector<int> &arr, int index, int target, vector<vector<int>> &dp){
        int n = arr.size();
        if (target < 0) return 0;
        if (index == n){
            if (target == 0) return 1;
            return 0;
        }
        if (dp[index][target] != -1) return dp[index][target];
        
        int include = solve(arr, index + 1, target - arr[index], dp);
        int exclude = solve(arr, index + 1, target, dp);
        
        return dp[index][target] = include + exclude;
    }
    int solve(vector<int> &arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        
        for (int i = n - 1; i >= 0; i--){
            for (int j = 0; j <= target; j++){
                int include = 0;
                if (j >= arr[i]){
                    include = dp[i + 1][j - arr[i]];
                }
                int exclude = dp[i + 1][j];
                
                dp[i][j] = include + exclude;
            }
        } 
        
        return dp[0][target];
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int index = 0;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        // int ans = solve(arr, index, target, dp);
        int ans = solve(arr, target);
        
        return ans;
    }
};
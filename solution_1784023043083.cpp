class Solution {
  public:
    bool solve(vector<int> &arr, int index, int target, vector<vector<int>> &dp){
        if (target == 0) return true;
        if (index >= arr.size() || target < 0) return false;
        if (dp[index][target] != -1) return dp[index][target];
        
        bool ansleft = solve(arr, index + 1, target - arr[index], dp);
        bool ansright = solve(arr, index + 1, target, dp);
        
        return dp[index][target] = ansleft || ansright;
    }
    bool solve(vector<int> &arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        
        for (int i = n - 1; i >= 0; i--){
            for (int j = 1; j <= sum; j++){
                bool ansleft = false;
                if (j >= arr[i]) ansleft = dp[i + 1][j - arr[i]];
                bool ansright = dp[i + 1][j];
                
                dp[i][j] = ansleft || ansright;
            }
        }
        
        return dp[0][sum];
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        int index = 0;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        // bool ans = solve(arr, index, sum, dp);
        bool ans = solve(arr, sum);
        
        return ans;
    }
};
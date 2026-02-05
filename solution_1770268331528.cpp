class Solution {
public:
    // int solve(vector<int> &nums, int index, vector<int> &dp){
    //     int n = nums.size();
    //     if (index >= n) return 0;
    //     if (dp[index] != -1) return dp[index];
    //     int include = nums[index] + solve(nums, index + 2, dp);
    //     int exclude = solve(nums, index + 1, dp);

    //     return dp[index] = max(include, exclude);
    // }
    // int solve(vector<int> &nums){
    //     int n = nums.size();
    //     vector<int> dp(n + 2, 0);

    //     for (int i = n - 1; i >= 0; i--){
    //         int include = nums[i] + dp[i + 2];
    //         int exclude = dp[i + 1];

    //         dp[i] = max(include, exclude);
    //     }

    //     return dp[0];
    // }
    int solve(vector<int> &nums){
        int n = nums.size();
        int prev2 = 0;
        int prev1 = 0;

        for (int i = n - 1; i >= 0; i--){
            int include = nums[i] + prev2;
            int exclude = prev1;
            int curr = max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        // vector<int> dp(n + 1, -1);
        int ans = solve(nums);

        return ans;
    }
};
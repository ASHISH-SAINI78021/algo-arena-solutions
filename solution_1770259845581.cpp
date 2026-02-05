class Solution {
public:
    int solve(vector<int> &nums, int index, vector<int> &dp){
        int n = nums.size();
        if (index >= n) return 0;
        if (dp[index] != -1) return dp[index];
        int include = nums[index] + solve(nums, index + 2, dp);
        int exclude = solve(nums, index + 1, dp);

        return dp[index] = max(include, exclude);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        vector<int> dp(n + 1, -1);
        int ans = solve(nums, index, dp);

        return ans;
    }
};
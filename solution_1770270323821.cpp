class Solution {
public:
    // int solve(vector<int> &nums, int index, int n, vector<int> &dp){
    //     if (index >= n) return 0;
    //     if (dp[index] != -1) return dp[index];

    //     int include = nums[index] + solve(nums, index + 2, n, dp);
    //     int exclude = solve(nums, index + 1, n, dp);

    //     return dp[index] = max(include, exclude);
    // }
    int solve(vector<int> nums, int start, int end){
        vector<int> dp(end + 3, 0);
        for (int i = end; i >= start; i--){
            int include = nums[i] + dp[i + 2];
            int exclude = dp[i + 1];

            dp[i] = max(include, exclude);
        }

        return dp[start];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int index = 0;
        int ans1 = solve(nums, 0, n - 2);
        int ans2 = solve(nums, 1, n - 1);

        return max(ans1, ans2);
    }
};
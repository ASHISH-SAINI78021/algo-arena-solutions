class Solution {
public:
    int solve(vector<int> &nums, int index, int n, vector<int> &dp){
        if (index >= n) return 0;
        if (dp[index] != -1) return dp[index];

        int include = nums[index] + solve(nums, index + 2, n, dp);
        int exclude = solve(nums, index + 1, n, dp);

        return dp[index] = max(include, exclude);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int index = 0;
        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);
        int ans1 = solve(nums, index, n - 1, dp1);
        int ans2 = solve(nums, index + 1, n, dp2);

        return max(ans1, ans2);
    }
};
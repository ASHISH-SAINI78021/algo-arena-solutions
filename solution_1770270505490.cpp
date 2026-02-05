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
        int prev1 = 0;
        int prev2 = 0;
        for (int i = end; i >= start; i--){
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
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int index = 0;
        int ans1 = solve(nums, 0, n - 2);
        int ans2 = solve(nums, 1, n - 1);

        return max(ans1, ans2);
    }
};
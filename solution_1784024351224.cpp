class Solution {
public:
    bool solve(vector<int> &nums, int index, int target, vector<vector<int>> &dp){
        int n = nums.size();
        if (target == 0) return true;
        if (index >= n || target < 0) return false;
        if (dp[index][target] != -1) return dp[index][target];

        bool ansleft = solve(nums, index + 1, target - nums[index], dp);
        bool ansright = solve(nums, index + 1, target, dp);

        return dp[index][target] = ansleft || ansright;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int target = sum/2;
        int index = 0;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        bool ans = solve(nums, index, target, dp);

        return ans;
    }
};
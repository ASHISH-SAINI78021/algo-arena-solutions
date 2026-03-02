class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        int maxi = nums[0];
        int maxP = nums[0];

        for (int i = 1; i < n; i++){
            if (nums[i] < 0) swap(maxi, mini);
            maxi = max(nums[i], maxi*nums[i]);
            mini = min(nums[i], mini*nums[i]);
            maxP = max(maxP, maxi);
        }

        return maxP;
    }
};
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int count = 0;
        if (n == 1) return nums[0] == 1 ? 1 : 0;
        // if (nums[0] == 1) count = 1;
        for (int i = 0; i < n; i++){
            if (i == 0){
                if (nums[i] == 1){
                    count = 1;
                    maxi = max(maxi, count);
                }
                continue ;
            }
            if (nums[i] == nums[i - 1] && nums[i] == 1){
                count++;
                maxi = max(maxi, count);
            }
            else count = 1;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (maxi == 0 && sum != 0){
            return 1;
        }

        return maxi;
    }
};
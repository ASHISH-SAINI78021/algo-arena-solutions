class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mini = INT_MAX;
        int ans = -1;

        for (int i = 0; i < n; i++){
            int j = i + 1;
            int k = n - 1;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if (mini > abs(target - sum)){
                    mini = abs(target - sum);
                    ans = sum;
                }
                if (sum > target) k--;
                else j++;
            }
        }

        return ans;
    }
};

// nums = -4 -1 1 2   target = 1

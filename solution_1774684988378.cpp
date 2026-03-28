class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // O(nlogn)
        int mini = INT_MAX;
        int ans = -1;


        for (int i = 0; i < n; i++){
            int j = i + 1;
            int k = n - 1;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if (mini > abs(sum - target)){
                    mini = abs(sum - target);
                    ans = sum;
                }
                else if (sum > target) k--;
                else j++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        // prefixSum + hashing
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            if (sum == goal) count++;
            if (mp.find(sum - goal) != mp.end()){
                count += mp[sum - goal];class Solution {
public:
    int solve(vector<int> &nums, int k){
        int n = nums.size();
        int l = 0; int r = 0;
        unordered_map<int, int> mp;
        int odd = 0;
        int count = 0;
        while (r < n){
            if (nums[r] & 1) odd++;
            while (odd > k){
                if (nums[l] & 1) odd--;
                l++;
            }
            count += r - l + 1;
            r++;
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
            }
            mp[sum]++;
        }

        return count;
    }
};
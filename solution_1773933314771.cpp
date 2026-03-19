class Solution {
public:
    int solve(vector<int> &nums, int k){
        int n = nums.size();
        int l = 0; int r = 0;
        int odd = 0;
        int count = 0;
        while (r < n){
            if (nums[r] & 1) odd++;
            while (odd > k){
                if ((nums[l] & 1) && l <= r) odd--;
                l++;
            }
            count += r - l + 1;
            r++;
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = solve(nums, k) - solve(nums, k - 1);
        return ans;
    }
};

// When its my time to win, I cannot lose
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++){
            ans[i] = prefix;
            prefix = prefix*nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--){
            ans[i] *= suffix;
            suffix = suffix * nums[i];
        }

        return ans;
    }
};



// nums = 1 2 3 4
// o/p = 24 12 8 6

// Brute force solution 
// Time complexity -> O(n2)
// Space Complexity -> O(1)


// product at i = left of i * right of i
// Time Complexity -> O(n)
// Space Complexity -> o(n)
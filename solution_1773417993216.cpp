class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = 0; i < n; i++){
            if (i == 0 && 0 == (prefix[n - 1] - prefix[i])) return 0;
            else if (i == n - 1 && prefix[i - 1] == 0) return n - 1;
            else if (i > 0 && i < n - 1 && prefix[i - 1] == prefix[n - 1] - prefix[i]) return i;
        }

        return -1;
    }
};



// nums = 1 7 3 6 5 6 

// prefix = 1 8 11 17 22 28
//         prefix[n - 1] - prefix[i]

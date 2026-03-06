class Solution {
public:
    bool isSafe(vector<int> &nums, int &maxSum, int k){
        int n = nums.size();
        int sum = 0;
        int count = 1;
        for (int i = 0; i < n; i++){
            if (nums[i] > maxSum) return false;
            if (sum + nums[i] <= maxSum){
                sum += nums[i];
            }
            else {
                count++;
                sum = nums[i];
            }
        }


        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return 0;
        int start = *min_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while (start <= end){
            int mid = start + (end - start)/2;
            if (isSafe(nums, mid, k)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return ans;
    }
};


// nums = 7 2 5 10 8    k = 2
// [7], [2 5 10 8] -> maxSum = 25
// [7 2], [5 10 8] -> maxSum = 23
// [7 2 5], [10 8] -> maxSum = 18 ->> ans
// [7 2 5 10], [8] -> maxSum = 26

// logic
// min_element(2).......sum(n) -> I'll check one by one i.e if maxSum = i then it could be divisible to k subarrays or not ?
// i.e I'll check 
// maxSum = 2 3 4 5 ...... sum(n) -> monotonic behaviour -> so I can use here B.S

// isSafe()
// count = 1
// sum + nums[i] <= maxSum -> sum += nums[i] else count++ and sum = nums[i]
// count <= k
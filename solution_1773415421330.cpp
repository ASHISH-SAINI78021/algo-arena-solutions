class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int count = 0;
        int sum = 0;

        for (int i = 0; i < n; i++){
            sum += nums[i];
            if (sum == k){
                count++;
            }
            if (mp.find(sum - k) != mp.end()){
                count += mp[sum - k];
            }
            mp[sum]++;
        }

        return count;
    }
};



// nums = [1,1,1] k = 2 -> sum
// 1 2 3
// 1 2
// 1
// output -> 2


// Brute 
// Time complexity -> O(n3)
// Space Complexity -> O(n2)*O(n) -> O(n3)


// nums = 1 1 1
// prefixSum = 1 2 3

// requiredSum = prefixSum[n - 1] - prefixSum[1 - 1] -> 3 - 1 = 2
//     k       = prefixSum[j] - prefixSum[i - 1]

// hashing -> lemme show how we can do this ?
// prefixSum[i - 1] = prefixSum[j] - k
// count = count + mp[prefixSum[i - 1]];
// 1 -> 4
// 2 -> 1
// 3 -> 1


// Time Complexity: O(n)
// Space Complexity: O(n) + O(n)
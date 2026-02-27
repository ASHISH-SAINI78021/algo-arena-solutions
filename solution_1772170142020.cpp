class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        int maxi = 0;
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += arr[i];
            if (sum == k){
                maxi = max(maxi, i + 1);
            }
            
            if (mp.find(sum - k) != mp.end()){
                maxi = max(maxi, i - mp[sum - k] + 1);
            }
            
            if (mp.find(sum) == mp.end()){
                mp[sum] = i + 1;
            }
        }
        
        return maxi;
    }
};
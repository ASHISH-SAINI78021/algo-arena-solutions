class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int maxi = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            sum += arr[i];
            if (sum == 0){
                maxi = max(maxi, i + 1);
            }
            if (mp.find(sum) != mp.end()){
                maxi = max(maxi, i - mp[sum]);
            }
            
            if (mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        
        
        return maxi;
    }
};
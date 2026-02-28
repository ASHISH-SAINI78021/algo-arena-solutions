class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        long ans = 0;
        unordered_map<int, int> mp;
        int Xor = 0;
        for (int i = 0; i < n; i++){
            Xor = Xor ^ arr[i];
            if (Xor == k){
                ans++;
            }
            int target = Xor ^ k;
            if (mp.find(target) != mp.end()){
                ans += mp[target];
            }
            
            mp[Xor]++;
        }
        
        return ans;
    }
};
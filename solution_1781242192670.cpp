class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int Xor = 0;
        int count = 0;
        for (int i = 0; i < n; i++){
            Xor = Xor^arr[i];
            if (Xor == k){
                count++;
            }
            if (mp.find(k ^ Xor) != mp.end()){
                count += mp[k ^ Xor];
            }
            mp[Xor]++;
        }
        
        return count;
    }
};


// k = Xor ^ prefix[i - 1];
// k^Xor = prefix[i - 1];



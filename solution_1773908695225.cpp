class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        int l = 0;
        int r = 0;
        unordered_map<char, int> mp;
        int maxi = -1;
        while (r < n){
            mp[s[r]]++;
            while (mp.size() > k){
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            if (mp.size() == k) maxi = max(maxi, r - l + 1);
            r++;
        }
        
        return maxi;
    }
};
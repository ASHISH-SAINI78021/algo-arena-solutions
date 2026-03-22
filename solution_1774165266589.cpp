class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;
        unordered_map<char, int> mp;

        int l = 0; int r = 0;
        while (r < n){
            mp[s[r]]++;
            while (r - l + 1 > mp.size()){
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0 || n == 1) return n;
        int maxi = 0;

        unordered_map<int, int> mp;
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

// r - l + 1 > mp.size();
// abc mp = 3
// abcd mp = 4
// abcdd mp 4
// d -> 2
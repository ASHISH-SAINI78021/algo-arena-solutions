class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int start = 0;
        int end = 0;
        unordered_map<char, int> mp;
        for (auto it : t) mp[it]++;
        int required = t.size();
        int l = 0;
        int r = 0;
        int mini = INT_MAX;

        while (r < n){
            if (mp.find(s[r]) != mp.end()){
                if (mp[s[r]] > 0) required--;
                mp[s[r]]--;
            }
            while (required == 0){
                if (mini > r - l + 1){
                    mini = r - l + 1;
                    start = l;
                    end = r - l + 1;
                }
                if (mp.find(s[l]) != mp.end()){
                    mp[s[l]]++;
                    if (mp[s[l]] > 0) required++;
                }
                l++;
            }
            r++;
        }

        return s.substr(start, end);
    }
};
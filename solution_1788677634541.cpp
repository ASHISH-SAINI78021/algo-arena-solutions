class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int required = t.size();
        unordered_set<char> st (t.begin(), t.end());
        unordered_map<char, int> mp;
        for (auto it : t) mp[it]++;
        int mini = INT_MAX;
        // string ans = "";
        int start = 0;
        int end = 0;
        int l = 0;
        int r = 0;
        while (r < n){
            if (st.find(s[r]) != st.end()){
                if (mp[s[r]] > 0) required--;
                mp[s[r]]--;
            }

            // shrinking the window
            while (required == 0){
                // cout << l << " ";
                if (mini > r - l + 1){
                    mini = r - l + 1;
                    // ans = s.substr(l, r - l + 1);
                    start = l;
                    end = r - l + 1;
                    // cout << "ans -> " << ans << endl;
                }
                if (mp.find(s[l]) != mp.end()){
                    mp[s[l]]++;
                    if (mp[s[l]] > 0) required++;
                }

                l++;
            }

            // cout << "Window - > " << s.substr(l, r - l + 1) << endl;

            r++;
        }

        return s.substr(start, end);
    }
};


// Time Complexity - > O(n + m)
// Space Complexity - > O(1)
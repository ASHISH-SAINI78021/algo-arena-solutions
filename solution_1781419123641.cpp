class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans; 
        vector<int> Pcount(26, 0);
        vector<int> Scount(26, 0);
        int n = s.length();
        int m = p.length();

        if (n < m) return ans;

        for (int i = 0; i < m; i++){
            Pcount[p[i] - 'a']++;
        }

        int left = 0; int right = 0;
        while (right < n){
            Scount[s[right] - 'a']++;
            while (right - left + 1 >= m){
                if (Pcount == Scount) ans.push_back(left);
                Scount[s[left] - 'a']--;
                left++;
            }

            right++;
        }

        return ans;
    }
};
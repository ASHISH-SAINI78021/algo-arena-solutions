class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < m; i++){
            freq[t[i] - 'a']--;
            if (freq[t[i] - 'a'] < 0) return false;
        }

        int sum = accumulate(freq.begin(), freq.end(),0);
        if (sum != 0) return false;


        return true;
    }
};
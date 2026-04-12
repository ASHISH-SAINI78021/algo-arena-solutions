class Solution {
public:
    bool solve(string &s, int index, unordered_set<string> &st, vector<int> &dp){
        // base case
        if (index == s.size()) return true;
        if (dp[index] != -1) return dp[index];

        // solution for one case
        string word = "";
        for (int i = index; i < s.length(); i++){
            word += s[i];
            if (st.find(word) != st.end()){
                if (solve(s, i + 1, st, dp)) return dp[i] = true;
            }
        }

        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(n + 1, -1);
        int index = 0;

        bool ans = solve(s, index, st, dp);
        return ans;
    }
};
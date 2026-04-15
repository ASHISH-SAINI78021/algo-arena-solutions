class Solution {
public:
    void solve(string &digits, int index, unordered_map<int, string> &mp, string &temp, vector<string> &ans){
        // base case
        if (index >= digits.size()){
            ans.push_back(temp);
            return ;
        }

        // solution for one case
        string s = mp[digits[index] - '0'];
        for (int i = 0; i < s.length(); i++){
            temp.push_back(s[i]);
            solve(digits, index + 1, mp, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ans;
        int index = 0;

        unordered_map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string temp = "";
        solve(digits, index, mp, temp, ans);

        return ans;
    }
};
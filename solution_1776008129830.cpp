class Solution {
public:
    void solve(string temp, int open, int close, vector<string> &ans){
        // base case
        if (open < 0 || close < 0) return ;
        if (open == 0 && close == 0){
            ans.push_back(temp);
            return ;
        }

        // solution for one case
        if (open > 0){
            solve(temp + '(', open - 1, close, ans);
        }
        if (close > open){
            solve(temp + ')', open, close - 1, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = n;
        int close = n;

        string temp;
        solve(temp, open, close, ans);

        return ans;
    }
};
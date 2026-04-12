class Solution {
public:
    void solve(string temp, int len, int prev, vector<string> &ans){
        if (len == 0){
            ans.push_back(temp);
            return ;
        }

        if (prev == 1 || prev == -1){
            solve(temp + '0', len - 1, 0, ans);
        }
        solve(temp + '1', len - 1, 1, ans);
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        int prev = -1;
        int len = n;

        string temp;
        solve(temp, len, prev, ans);

        return ans;
    }
};
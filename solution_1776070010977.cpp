class Solution {
public:
    void solve(vector<int> &candidates, int index, int target, vector<int> &temp, vector<vector<int>> &ans){
        // base case
        int n = candidates.size();
        if (target == 0){
            ans.push_back(temp);
            return ;
        }

        // solution for one case
        for (int i = index; i < n; i++){
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break ;
            temp.push_back(candidates[i]);
            solve(candidates, i + 1, target - candidates[i], temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        int index = 0;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, index, target, temp, ans);

        return ans;
    }
};
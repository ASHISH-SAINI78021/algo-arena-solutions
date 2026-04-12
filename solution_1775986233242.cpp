class Solution {
public:
    void solve(vector<int> &candidates, int index, int target, vector<int> &temp, vector<vector<int>> &ans){
        // base case
        if (target < 0){
            return ;
        }
        if (target == 0){
            ans.push_back(temp);
            return ;
        }
        if (index >= candidates.size()) return ;

        // solution for one case
        if (candidates[index] <= target){
            temp.push_back(candidates[index]);
            solve(candidates, index, target - candidates[index], temp, ans);
            temp.pop_back();
        }
        solve(candidates, index + 1, target, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        int index = 0;
        
        vector<int> temp;
        solve(candidates, index, target, temp, ans);

        return ans;
    }
};
class Solution {
public:
    void solve(vector<int> &nums, vector<int> &temp, vector<bool> &used, vector<vector<int>> &ans){
        // base case
        if (temp.size() == nums.size()){
            ans.push_back(temp);
            return ;
        }

        // solution for one case
        for (int i = 0; i < nums.size(); i++){
            if (used[i]) continue ;
            temp.push_back(nums[i]);
            used[i] = true;
            solve(nums, temp, used, ans);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<bool> used(n, false);
        vector<int> temp;

        solve(nums, temp, used, ans);

        return ans;
    }
};
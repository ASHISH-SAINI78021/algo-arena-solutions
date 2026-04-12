class Solution {
public:
    void solve(vector<int> &nums, vector<int> &temp, vector<bool> &used, vector<vector<int>> &ans){
        int n = nums.size();
        // base case
        if (temp.size() == nums.size()){
            ans.push_back(temp);
            return ;
        }

        // solution for one case
        for (int i = 0; i < n; i++){
            if (used[i]) continue ;
            // tracking the duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue ;
            used[i] = true;
            temp.push_back(nums[i]);
            solve(nums, temp, used, ans);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(n, false);
        sort(nums.begin(), nums.end());
        solve(nums, temp, used, ans);

        return ans;
    }
};
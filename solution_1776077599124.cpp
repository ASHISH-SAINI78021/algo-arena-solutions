class Solution {
public:
    void solve(vector<int> &nums, int index, int k, int target, vector<vector<int>> &ans, vector<int> &temp){
        // base case
        if (target == 0 && temp.size() == k){
            ans.push_back(temp);
            return ;
        }
        if (index >= nums.size() || temp.size() > k || target < 0) return ;

        // solution for one case
        temp.push_back(nums[index]);
        solve(nums, index + 1, k, target - nums[index], ans, temp);
        temp.pop_back();
        solve(nums, index + 1, k, target, ans, temp);
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> ans;
        vector<int> nums;
        vector<int> temp;
        int index = 0;
        for (int i = 1; i <= 9; i++) nums.push_back(i);

        solve(nums, index, k, target, ans, temp);

        return ans;
    }
};
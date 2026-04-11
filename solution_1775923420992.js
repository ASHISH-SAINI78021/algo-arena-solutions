class Solution {
public:
    void solve(vector<int> &nums, int index, vector<int> &temp, vector<vector<int>> &ans){
        ans.push_back(temp);
        for (int i = index; i < nums.size(); i++){
            if (i > index && nums[i] == nums[i - 1]) continue ;

            temp.push_back(nums[i]);
            solve(nums, i + 1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());

        int index = 0;
        solve(nums, index, temp, ans);
        return ans;
    }
};
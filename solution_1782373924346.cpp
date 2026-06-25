/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int target, vector<int> &temp, vector<vector<int>> &ans){
        if (root == NULL){
            return ;
        }
        if (root->left == NULL && root->right == NULL && root->val == target){
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return ;
        }

        temp.push_back(root->val);
        solve(root->left, target - root->val, temp, ans);
        solve(root->right, target - root->val, temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        vector<int> temp;
        solve(root, target, temp, ans);

        return ans;
    }
};
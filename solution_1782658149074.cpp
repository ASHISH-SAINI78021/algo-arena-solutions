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
    void solve(TreeNode* root, string temp, vector<string> &ans){
        if (root == NULL) return ;
        if (root->left == NULL && root->right == NULL){
            temp += to_string(root->val);
            ans.push_back(temp);
            return ;
        }
        solve(root->left, temp + to_string(root->val) + "->", ans);
        solve(root->right, temp + to_string(root->val) + "->", ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL) return ans;
        string temp;
        solve(root, temp, ans);

        return ans;
    }
};
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
    void solve(TreeNode* root, int value, int &ans){
        if (root == NULL) return ;
        if (value <= root->val){
            value = max(value, root->val);
            ans++;
        }
        solve(root->left, value, ans);
        solve(root->right, value, ans);
    }
    int goodNodes(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        int ans = 0;
        int value = root->val;
        solve(root, value, ans);

        return ans;
    }
};
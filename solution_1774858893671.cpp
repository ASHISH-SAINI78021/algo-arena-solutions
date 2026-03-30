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
    TreeNode* solve(TreeNode* root){
        if (root == NULL) return NULL;
        auto ansleft = solve(root->left);
        auto ansright = solve(root->right);
        root->right = ansleft;
        root->left = ansright;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        root = solve(root);
        return root;
    }
};
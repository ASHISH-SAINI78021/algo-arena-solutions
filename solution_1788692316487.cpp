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
    int d = 0;
    int solve(TreeNode* root){
        if (root == NULL) return 0;
        int ansleft = solve(root->left);
        int ansright = solve(root->right);
        d = max(d, ansleft + ansright);

        return max(ansleft, ansright) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        solve(root);

        return d;
    }
};
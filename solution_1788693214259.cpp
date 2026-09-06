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
    int solve(TreeNode* root){
        if (root == NULL) return 0;
        int ansleft = solve(root->left);
        int ansright = solve(root->right);
        if (abs(ansright - ansleft) > 1) return 1e9;

        return max(ansleft, ansright) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int ans = solve(root);

        return (ans >= 1e9) ? false : true;
    }
};
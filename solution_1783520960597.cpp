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
    int maxi = INT_MIN;
    int solve(TreeNode* root){
        if (root == NULL) return 0;
        int ansleft = solve(root->left);
        int ansright = solve(root->right);
        ansleft = max(0, ansleft);
        ansright = max(0, ansright);
        maxi = max(maxi, ansleft + ansright + root->val);

        return root->val + max(ansleft, ansright);
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        solve(root);

        return maxi;
    }
};
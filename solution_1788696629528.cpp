/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == NULL) return root;
        if (p->val == root->val || q->val == root->val) return root;

        TreeNode* ansleft = solve(root->left, p, q);
        TreeNode* ansright = solve(root->right, p, q);

        if (ansleft != NULL && ansright == NULL) return ansleft;
        else if (ansleft == NULL && ansright != NULL) return ansright;
        else if (ansleft != NULL && ansright != NULL) return root;
        else return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
        TreeNode* ans = solve(root, p, q);

        return ans;
    }
};
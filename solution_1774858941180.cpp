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
        if (root == NULL){
            return NULL;
        }
        if (root == p) return p;
        if (root == q) return q;

        auto ansleft = solve(root->left, p, q);
        auto ansright = solve(root->right, p, q);

        if (ansleft != NULL && ansright != NULL) return root;
        else if (ansleft == NULL && ansright != NULL) return ansright;
        else if (ansleft != NULL && ansright == NULL) return ansleft;
        else return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
        return solve(root, p, q);
    }
};
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
    bool solve(TreeNode* root, long long lowerbound, long long upperbound){
        if (root == NULL) return true;

        if (root->val > lowerbound && root->val < upperbound){
            bool ansleft = solve(root->left, lowerbound, root->val);
            bool ansright = solve(root->right, root->val, upperbound);

            return ansleft && ansright;
        }

        return false;
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        long long lowerbound = LLONG_MIN;
        long long upperbound = LLONG_MAX;
        return solve(root, lowerbound, upperbound);
    }
};
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
    bool solve(TreeNode* root, int target){
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL && root->val == target){
            return true;
        }
        bool ansleft = solve(root->left, target - root->val);
        bool ansright = solve(root->right, target - root->val);
        
        return ansleft || ansright;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;

        bool ans = solve(root, targetSum);

        return ans; 
    }
};
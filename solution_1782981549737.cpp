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
    unordered_map<int, int> mp;
    bool solve(TreeNode* root, int target){
        if (root == NULL) return false;
        if (mp.find(target - root->val) != mp.end()) return true;
        else mp[root->val] = root->val;
        
        bool ansleft = solve(root->left, target);
        bool ansright = solve(root->right, target);

        return ansleft || ansright;
    }
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        return solve(root, k);
    }
};
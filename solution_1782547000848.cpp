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
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int &postIndex, int inorderStart, int inorderEnd, unordered_map<int, int> &mp){
        if (inorderStart > inorderEnd || postIndex < 0) return NULL;
        int element = postorder[postIndex--];
        int rootIndex = mp[element];
        TreeNode* root = new TreeNode(element);
        root->right = solve(inorder, postorder, postIndex, rootIndex + 1, inorderEnd, mp);
        root->left = solve(inorder, postorder, postIndex, inorderStart, rootIndex - 1, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postIndex = n - 1;;
        int inorderStart = 0;
        int inorderEnd = n - 1;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) mp[inorder[i]] = i;

        TreeNode* root = solve(inorder, postorder, postIndex, inorderStart, inorderEnd, mp);

        return root;
    }
};
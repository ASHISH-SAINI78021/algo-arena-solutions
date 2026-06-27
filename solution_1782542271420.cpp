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
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inorderStart, int inorderEnd, unordered_map<int, int> &mp){
        if (inorderStart > inorderEnd || preIndex >= preorder.size()) return NULL; 
        int element = preorder[preIndex++];
        int rootIndex =  mp[element];
        TreeNode* root = new TreeNode(element);
        root->left = solve(preorder, inorder, preIndex, inorderStart, rootIndex - 1, mp);
        root->right = solve(preorder, inorder, preIndex, rootIndex + 1, inorderEnd, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = n - 1;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = solve(preorder, inorder, preIndex, inorderStart, inorderEnd, mp);

        return root;
    }
};
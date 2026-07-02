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
    vector<TreeNode*> arr;
    void inorder(TreeNode* root){
        if (root == NULL) return ;
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if (root == NULL) return ;
        inorder(root);
        int n = arr.size();
        if (n <= 2){
            swap(arr[0]->val, arr[1]->val);
            return ;
        }
        vector<TreeNode*> temp;
        for (int i = 1; i < n; i++){
            if (arr[i - 1]->val > arr[i]->val && temp.empty()){
                temp.push_back(arr[i - 1]);
                temp.push_back(arr[i]);
            }
            else if (arr[i - 1]->val > arr[i]->val && !temp.empty()){
                temp[1] = arr[i];
            }
        }

        swap(temp[0]->val, temp[1]->val);
    }
};
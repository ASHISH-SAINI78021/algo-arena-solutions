class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return ;
        
        flatten(root->left);
        flatten(root->right);

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* curr = root;
        while (curr && curr->right){
            curr = curr->right;
        }
        if (curr) curr->right = temp;
    }
};
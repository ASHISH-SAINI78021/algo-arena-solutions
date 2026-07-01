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
    TreeNode* inorderSuccessor(TreeNode* root){
        while (root && root->left){
            root = root->left;
        }
        return root;
    }
    TreeNode* solve(TreeNode* root, int key){
        if (root == NULL) return NULL;

        if (root->val == key){
            // case1: It's a leaf node
            if (root->left == NULL && root->right == NULL){
                TreeNode* node = root;
                delete node;
                return NULL;
            }
            // case2: It has only left child
            if (root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // case3: It has only right child
            if (root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // case4: It has its both children
            if (root->left != NULL && root->right != NULL){
                TreeNode* temp = inorderSuccessor(root->right);
                root->val = temp->val;
                root->right = solve(root->right, temp->val);
            }
        }
        else if (root->val > key){
            root->left = solve(root->left, key);
        }
        else {
            root->right = solve(root->right, key);
        }

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;
        root = solve(root, key);

        return root;
    }
};
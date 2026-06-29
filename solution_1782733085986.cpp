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
        while (root->left){
            root = root->left;
        }
        return root;
    }

    TreeNode* solve(TreeNode* root, int key){
        if (root == NULL) return NULL;

        if (root->val > key){
            root->left = solve(root->left, key);
        }
        else if (root->val < key){
            root->right = solve(root->right, key);
        }
        else{
            // Case 1: Leaf node
            if (root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            // Case 2: Only right child
            else if (root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 3: Only left child
            else if (root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 4: Both children exist
            else{
                TreeNode* temp = inorderSuccessor(root->right);
                root->val = temp->val;
                root->right = solve(root->right, temp->val);
            }
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return solve(root, key);
    }
};
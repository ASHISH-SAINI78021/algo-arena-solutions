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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        using T = pair<TreeNode*, unsigned long long>;
        queue<T> q;
        q.push({root, 0});
        unsigned long long maxi = 0;

        while (!q.empty()){
            int size = q.size();
            unsigned long long first = 0;
            unsigned long long last = 0;
            for (int i = 0; i < size; i++){
                auto front = q.front(); q.pop();
                TreeNode* node = front.first;
                unsigned long long index = front.second;
                if (i == 0) first = index;
                if (i == size - 1) last = index;
                if (node->left){
                    q.push({node->left, 2*index});
                }
                if (node->right){
                    q.push({node->right, 2*index + 1});
                }
            }
            maxi = max(maxi, last - first + 1);
        }

        return maxi;
    }
};
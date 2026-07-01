/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int minValue(Node* root) {
        if (root == NULL) return INT_MAX;
        int val1 = INT_MAX;
        if (root->left) val1 = minValue(root->left);
        else val1 = minValue(root->right);
        
        return min(val1, root->data);
    }
};
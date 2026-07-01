/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* solve1(Node* root){
        while (root && root->right){
            root = root->right;
        }
        return root;
    }

    Node* solve2(Node* root){
        while (root && root->left){
            root = root->left;
        }
        return root;
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;

        Node* curr = root;

        while (curr){
            if (curr->data == key){
                if (curr->left)
                    pre = solve1(curr->left);

                if (curr->right)
                    suc = solve2(curr->right);

                break;
            }
            else if (curr->data > key){
                suc = curr;
                curr = curr->left;
            }
            else{
                pre = curr;
                curr = curr->right;
            }
        }

        return {pre, suc};
    }
};
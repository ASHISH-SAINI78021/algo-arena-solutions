/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            auto front = q.front(); q.pop();
            if (front == NULL){
                ans += "N,";
            }
            else {
                ans += to_string(front->val) + ",";
                q.push(front->left);
                q.push(front->right);
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        stringstream ss(data);
        string temp;
        getline(ss, temp, ',');
        TreeNode* root = new TreeNode(stoi(temp));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            auto front = q.front(); q.pop();
            // left child
            if (getline(ss, temp, ',')){
                if (temp != "N"){
                    front->left = new TreeNode(stoi(temp));
                    q.push(front->left);
                }
            }
            // right child
            if (getline(ss, temp, ',')){
                if (temp != "N"){
                    front->right = new TreeNode(stoi(temp));
                    q.push(front->right);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
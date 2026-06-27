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
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        map<int, int> mp;
        using T = pair<Node*, int>;
        queue<T> q;
        q.push({root, 0});
        
        while (!q.empty()){
            auto front = q.front(); q.pop();
            int hd = front.second;
            Node* node = front.first;
            mp[hd] = node->data;
            
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        
        for (auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
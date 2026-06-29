/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int minTime(Node* root, int t) {
        if (root == NULL) return 0;
        Node* target;
        unordered_map<Node*, Node*> mp;
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()){
            auto front = q.front(); q.pop();
            if (front->data == t) target = front;
            if (front->left){
                q.push(front->left);
                mp[front->left] = front;
            }
            if (front->right){
                q.push(front->right);
                mp[front->right] = front;
            }
        }
        
        queue<pair<Node*, int>> qq;
        qq.push({target, 0});
        int maxi = 0;
        
        while (!qq.empty()){
            auto front = qq.front(); qq.pop();
            Node* node = front.first;
            int cost = front.second;
            maxi = max(maxi, cost);
            
            if (node->left && !visited[node->left]){
                qq.push({node->left, cost + 1});
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right]){
                qq.push({node->right, cost + 1});
                visited[node->right] = true;
            }
            if (mp[node] && !visited[mp[node]]){
                qq.push({mp[node], cost + 1});
                visited[mp[node]] = true;
            }
        }
        
        return maxi;
    }
};
















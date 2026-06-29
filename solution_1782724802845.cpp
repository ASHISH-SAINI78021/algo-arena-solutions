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

        Node* target = NULL;
        unordered_map<Node*, Node*> mp;
        unordered_map<Node*, bool> visited;

        queue<Node*> q;
        q.push(root);
        mp[root] = NULL;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            if (front->data == t)
                target = front;

            if (front->left) {
                q.push(front->left);
                mp[front->left] = front;
            }

            if (front->right) {
                q.push(front->right);
                mp[front->right] = front;
            }
        }

        queue<pair<Node*, int>> qq;
        qq.push({target, 0});
        visited[target] = true;

        int maxi = 0;

        while (!qq.empty()) {
            auto front = qq.front();
            qq.pop();

            Node* node = front.first;
            int cost = front.second;

            maxi = max(maxi, cost);

            if (node->left && !visited[node->left]) {
                visited[node->left] = true;
                qq.push({node->left, cost + 1});
            }

            if (node->right && !visited[node->right]) {
                visited[node->right] = true;
                qq.push({node->right, cost + 1});
            }

            if (mp[node] && !visited[mp[node]]) {
                visited[mp[node]] = true;
                qq.push({mp[node], cost + 1});
            }
        }

        return maxi;
    }
};
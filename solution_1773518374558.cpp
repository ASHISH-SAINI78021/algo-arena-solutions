/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        Node* graph = new Node(node->val);
        unordered_map<Node*, Node*> mp;
        mp[node] = graph;
        queue<Node*> q;
        q.push(node);

        while (!q.empty()){
            auto front = q.front(); q.pop();
            for (auto it : front->neighbors){
                if (mp.find(it) == mp.end()){
                    mp[it] = new Node(it->val);
                    q.push(it);
                }
                mp[front]->neighbors.push_back(mp[it]);
            }
        }

        return graph;
    }
};
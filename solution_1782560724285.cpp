class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()){
            auto front = q.front(); q.pop();
            Node* node = front.first;
            int hd = front.second;
            
            if (mp.find(hd) == mp.end()) mp[hd] = node->data;
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        
        for (auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};

//     (0)
//     1 
// (-1)   (+1)
// 2       3

// -1 -> 2
// 0 -> 1
// +1 -> 3

// ans = 2 1 3

// T.C -> O(n)
// S.C -> O(n)

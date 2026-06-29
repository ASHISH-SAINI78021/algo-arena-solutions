/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans, unordered_map<TreeNode*, TreeNode*> &mp, int k, unordered_map<TreeNode*, bool> &visited){
        if (root == NULL || visited[root]) return;

        if (k == 0){
            ans.push_back(root->val);
            return ;
        }

        visited[root] = true;
        solve(root->left, ans, mp, k - 1, visited);
        solve(root->right, ans, mp, k - 1, visited);
        solve(mp[root], ans, mp, k - 1, visited);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (root == NULL) return ans;
        unordered_map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);
        mp[root] = NULL;
        int len = 0;
        while (!q.empty()){
            auto front = q.front(); q.pop();
            len++;
            if (front->left){
                mp[front->left] = front;
                q.push(front->left);
            }
            if (front->right){
                mp[front->right] = front;
                q.push(front->right);
            }
        }

        unordered_map<TreeNode*, bool> visited;

        solve(target, ans, mp, k, visited);

        return ans;
    }
};
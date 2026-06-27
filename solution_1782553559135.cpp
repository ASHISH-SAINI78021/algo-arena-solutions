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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        using T = pair<int, pair<int, TreeNode*>>;
        queue<T> q;
        q.push({0, {0, root}});
        map<int, map<int, multiset<int>>> mp;

        while (!q.empty()){
            auto front = q.front(); q.pop();
            int col = front.first;
            int row = front.second.first;
            TreeNode* node = front.second.second;
            mp[col][row].insert(node->val);
            if (node->left) q.push({col - 1, {row + 1, node->left}});
            if (node->right) q.push({col + 1, {row + 1, node->right}});
        }

        for (auto col : mp){
             vector<int> temp;
            for (auto row : col.second){
                for (auto it : row.second){
                    temp.push_back(it);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
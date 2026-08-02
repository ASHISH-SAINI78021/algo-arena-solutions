class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root, int maxi){
        if (root == NULL) return ;
        if (root->val >= maxi){
            ans++;
            maxi = root->val;
        }

        solve(root->left, maxi);
        solve(root->right, maxi);
    }
    int goodNodes(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        int maxi = INT_MIN;
        solve(root, maxi);

        return ans;
    }
};
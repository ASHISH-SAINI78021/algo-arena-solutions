class Solution {
public:
    int maxi = INT_MIN;
    int solve(TreeNode* root){
        if (root == NULL) return 0;
        int ansleft = solve(root->left);
        int ansright = solve(root->right);
        ansleft = max(0, ansleft);
        ansright = max(0, ansright);
        maxi = max(maxi, ansleft + ansright + root->val);
        return root->val + max(ansleft, ansright);
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        int ans = solve(root);

        return maxi;
    }
};


// T.C -> O(n)
// S.C -> O(n)
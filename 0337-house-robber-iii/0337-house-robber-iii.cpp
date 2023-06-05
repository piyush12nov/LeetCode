/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
    int ff(TreeNode *root, int v,  map<pair<TreeNode*, int>, int> &dp)
    {
        if (root == nullptr) return 0;

        if (dp.find({ root,v }) != dp.end()) return dp[{ root,v }];
        int a = 0, b = 0;
        if (v - 1 <= 0)
        {
            a = root->val + ff(root->left, 2, dp) + ff(root->right, 2, dp);
        }
        b = ff(root->left, min(v - 1, 0), dp) + ff(root->right, min(0, v - 1), dp);

        return dp[{ root,v }] = max(a, b);
    
    }
    int rob(TreeNode *root)
    {
        map<pair<TreeNode*, int>, int> dp;
        return ff(root, 0,dp);
    }
};
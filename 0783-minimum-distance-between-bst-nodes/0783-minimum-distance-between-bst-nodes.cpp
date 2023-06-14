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
    int prev = INT_MAX, ans = INT_MAX;
    void dfs(TreeNode *root)
    {
        if (root == nullptr) return;
        dfs(root->left);
        ans = min(ans, abs(prev - root->val));
        prev = root->val;
        dfs(root->right);
    }
    int minDiffInBST(TreeNode *root)
    {
        dfs(root);

        return ans;
    }
};
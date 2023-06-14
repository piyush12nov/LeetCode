/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        int s1 = INT_MAX, prev = INT_MAX, ans = INT_MAX;
    void ff(TreeNode *root)
    {
        if (root == nullptr) return;
        if (root->left)
            ff(root->left);
        ans = min(ans, abs(root->val - prev));
        prev = root->val;
        cout<<root->val<<" ";
        if (root->right)
            ff(root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        ff(root);
        cout << endl;
        return ans;
    }
};
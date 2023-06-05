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
    map<pair<TreeNode*, int>, int> dp;
    int ff(TreeNode *root, int v)
    {
        if (root == nullptr) return 0;
       	//     cout<<root->val<<" "<<v-1<<endl;
        if (dp.find({ root,v }) != dp.end()) return dp[{ root,v }];
        int a = 0, b = 0;
        if (v - 1 <= 0)
        {
            a = root->val + ff(root->left, 2) + ff(root->right, 2);
        }
        b = ff(root->left, min(v - 1, 0)) + ff(root->right, min(0, v - 1));
       	//    cout<<max(a,b)<<" TTTTTTTTTT  "<<root->val<<endl;
        return dp[{ root,v }] = max(a, b);
    }
    int rob(TreeNode *root)
    {
        return ff(root, 0);
    }
};
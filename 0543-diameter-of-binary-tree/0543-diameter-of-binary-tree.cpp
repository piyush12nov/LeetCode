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
    int ans = 0;
    int ff(TreeNode* root)
    {
        if(root==nullptr)return 0;
        int le=ff(root->left);
        int re=ff(root->right);
        ans=max(ans,le+re);
        return 1+max(le,re);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ff(root);
        return ans;
    }
};
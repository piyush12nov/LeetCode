/*
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
    int ans=0;
    int ff(TreeNode* root)
    {
        if(!root)return 0;
        int x=ff(root->left);
        int y=ff(root->right);
        ans=max(ans,x+y);
        return max(x,y)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ff(root);
        return ans;
    }
};
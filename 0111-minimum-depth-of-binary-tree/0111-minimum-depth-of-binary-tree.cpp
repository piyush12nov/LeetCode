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
    int ans = INT_MAX;
    void ff(TreeNode* root,int cnt)
    {
        if(root->right==nullptr&&root->left==nullptr)
        {
            ans=min(cnt,ans);
            return;
        }
        if(root->right)
        ff(root->right,cnt+1);
        if(root->left)
        ff(root->left,cnt+1);
        
    }
    int minDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        ff(root,1);
        return ans;
    }
};
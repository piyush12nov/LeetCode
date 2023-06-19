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
    int tt=0,k,ans;
    void ff(TreeNode* root) {
        if(root==nullptr)return ;
        if(root->left)
           ff(root->left);
        tt++;
        if(tt==k)
        {
            ans=root->val;
            return ;
        }
        if(root->right)
            ff(root->right);
    }
    int kthSmallest(TreeNode* root, int kk) {
        k=kk;
        ff(root);
        return ans;
    }
};
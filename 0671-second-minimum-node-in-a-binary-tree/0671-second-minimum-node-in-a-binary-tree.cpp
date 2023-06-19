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
    int k=0,ans=INT_MAX;
    set<int>s;
    void ff(TreeNode* root)
    {
        if(root==nullptr)return ;
        if(root->left)
        {
            ff(root->left);
        }
        s.insert(root->val);
        if(root->right)
        {
            ff(root->right);
        }
    }
    int findSecondMinimumValue(TreeNode* root) 
    {
        ff(root);
        auto it=s.begin();
        it++;
        if(it==s.end())return -1;
        return *it;
        
    }
};
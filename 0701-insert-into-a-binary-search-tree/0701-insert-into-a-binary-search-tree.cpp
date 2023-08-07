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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp=new TreeNode(val);
        if(!root)return temp;
        TreeNode* cur=root;
        while(cur)
        {

            if(cur->val==val)return root;
            else if(cur->val<val)
            {
                if(!cur->right)break;
                cur=cur->right;
            }
            else
            {
                if(!cur->left)break;
                cur=cur->left;
            }
            
        }
        if(cur->val<val)
        {
            cur->right=temp;
        }
        else cur->left=temp;
         
        return root;
    }
};
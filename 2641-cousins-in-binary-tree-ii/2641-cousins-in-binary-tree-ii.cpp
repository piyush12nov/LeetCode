/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
/*/
class Solution
{
    public:

        TreeNode* replaceValueInTree(TreeNode *root)
        {
            queue<TreeNode*> q;
            q.push(root);
            root->val = 0;
            while (!q.empty())
            {
                int i, sum = 0, l = q.size();
                queue<TreeNode*> qq(q);
                for (i = 0; i < l; i++)
                {
                    auto it = qq.front();
                    qq.pop();
                    if (it->left)
                    {
                        sum += it->left->val;
                    }
                    if (it->right)
                    {
                        sum += it->right->val;
                    }
                }

                for (i = 0; i < l; i++)
                {
                    int curr = 0;
                    auto it = q.front();
                    q.pop();
                    if (it->left)
                    {
                        curr += it->left->val;
                        q.push(it->left);
                    }
                    if (it->right)
                    {
                        curr += it->right->val;
                        q.push(it->right);
                    }
                    if (it->left)
                    {
                        it->left->val = sum - curr;
                    }
                    if (it->right)
                    {
                        it->right->val = sum - curr;
                    }
                }
            }
            return root;
        }
};
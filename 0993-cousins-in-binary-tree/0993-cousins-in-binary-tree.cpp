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
        bool isCousins(TreeNode *root, int x, int y)
        {
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                int l = q.size(), tot = 0, to = 0;
                for (int i = 0; i < l; i++)
                {
                    to = 0;
                    auto it = q.front();
                    q.pop();
                    if (it->val == x) tot++;
                    if (it->val == y) tot++;
                    if (tot == 2) return 1;
                    if (it->left)
                    {
                        if (it->left->val == x || it->left->val == y) to++;
                        q.push(it->left);
                    }
                    if (it->right)
                    {
                        if (it->right->val == x || it->right->val == y) to++;
                        q.push(it->right);
                    }
                    if (to == 2) return 0;
                }
            }
            return 0;
        }
};
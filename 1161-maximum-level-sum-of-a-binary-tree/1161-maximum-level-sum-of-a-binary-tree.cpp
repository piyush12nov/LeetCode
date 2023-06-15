class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=INT_MIN,g=0;
        int req;
        while(!q.empty())
        {
            g++;
            int l=q.size();
            int s=0;
            for(int i=0;i<l;i++)
            {
                auto it=q.front();
                q.pop();
                s+=it->val;
                if(it->left)
                {
                    q.push(it->left);
                }
                if(it->right)
                {
                    q.push(it->right);
                }
            }
            if(s>ans)
            {
                ans=s;
                req=g;
            }
        }
        return req;
    }
};
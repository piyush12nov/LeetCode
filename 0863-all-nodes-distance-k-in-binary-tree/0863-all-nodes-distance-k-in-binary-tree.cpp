/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 *};

 */
class Solution
{
	public:
		vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
		{
			unordered_map<TreeNode*, TreeNode*> par;
			unordered_map<TreeNode*, int> vis;
			queue<TreeNode*> q;
			q.push(root);
			while (!q.empty())
			{
				auto it = q.front();
				q.pop();

				vis[it] = 0;
				if (it->left != nullptr)
				{
					par[it->left] = it;
					q.push(it->left);
				}

				if (it->right != nullptr)
				{
					q.push(it->right);
					par[it->right] = it;
				}
			
            }

			vector<int> ans;
			
            queue<pair<TreeNode*, int>> qq;
			qq.push({ target, k });

			while (!qq.empty())
			{
				int l = qq.size();
				for (int i = 0; i < l; i++)
				{
					auto ii = qq.front();
					qq.pop();

					TreeNode *it = ii.first;
					int cnt = ii.second;

					vis[it] = 1;
					
                    if (cnt == 0)
					{
						ans.push_back(it->val);
					}

					if (it->left != nullptr)
					{
						if (vis[it->left] == 0)
							qq.push({ it->left, cnt - 1 });
					}

					if (it->right != nullptr)
					{
						if (!vis[it->right])
							qq.push({ it->right, cnt - 1 });
					}

					if (par.find(it) != par.end() && !vis[par[it]])
					{
						qq.push({ par[it], cnt - 1 });
					}
				}
			}

			return ans;
		}
};

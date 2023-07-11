/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}

 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

 *};

 */
class Solution
{
	public:
		int amountOfTime(TreeNode *root, int start)
		{
			int ans = 0;
			unordered_map<TreeNode*, TreeNode*> par;
			unordered_map<TreeNode*, int> vis;
			TreeNode * starting;
			queue<TreeNode*> q;
			q.push(root);
			while (!q.empty())
			{
				auto it = q.front();
				q.pop();

				vis[it] = 0;
				if (it->val == start)
				{
					starting = it;
				}

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


			queue<pair<TreeNode*, int>> qq;
			qq.push({ starting, 0 });
			
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

                    ans = max(ans, cnt);
					
                    if (it->left != nullptr)
					{
						if (vis[it->left] == 0)
							qq.push({ it->left, cnt + 1 });
					}

					if (it->right != nullptr)
					{
						if (!vis[it->right])
							qq.push({ it->right, cnt + 1 });
					}

					if (par.find(it) != par.end() && !vis[par[it]])
					{
						qq.push({ par[it], cnt + 1 });
					}
				
                }
			}

			return ans;
		}
};

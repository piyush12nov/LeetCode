class Solution
{
    public:
        int shortestPath(vector<vector < int>> &grid, int k)
        {
            int n = grid.size(), m = grid[0].size();
            if (n == 1 && m == 1) return 0;
           
            queue<vector < int>> q;
            q.push({ 0, 0, k, 0 });
            vector<vector<vector< int>>> vis(n, vector<vector < int>> (m, vector<int> (k + 1, 0)));
            while (!q.empty())
            {
                int l = q.size();
                for (int o = 0; o < l; o++)
                {
                    auto v = q.front();
                    int i = v[0], j = v[1], k = v[2], re = v[3];
                    q.pop();
                    if (i == n - 1 && j == m - 1) return re;
                    if (vis[i][j][k] == 1) continue;
                    vis[i][j][k] = 1;
                    if (i + 1 < n)
                    {
                        if (k - grid[i + 1][j] >= 0)
                        {
                            q.push({ i + 1, j, k - grid[i + 1][j], re + 1 });
                        }
                    }
                    if (j + 1 < m)
                    {
                        if (k - grid[i][j + 1] >= 0)
                        {
                            q.push({ i, j + 1, k - grid[i][j + 1], re + 1 });
                        }
                    }
                    if (i - 1 >= 0)
                    {
                        if (k - grid[i - 1][j] >= 0)
                        {
                            q.push({ i - 1,j, k - grid[i - 1][j], re + 1 });
                        }
                    }
                    if (j - 1 >= 0)
                    {
                        if (k - grid[i][j - 1] >= 0)
                        {
                            q.push({ i, j - 1,  k - grid[i][j - 1], re + 1 });
                        }
                    }
                }
            }
            return -1;
        }
};
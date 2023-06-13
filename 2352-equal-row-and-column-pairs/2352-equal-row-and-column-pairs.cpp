class Solution
{
    public:
        int equalPairs(vector<vector < int>> &grid)
        {
            map<vector < int>, int> m;
            int i, j, n = grid.size(), ans = 0;
            for (i = 0; i < n; i++)
            {
                vector<int> t;
                for (j = 0; j < n; j++)
                {
                    t.push_back(grid[j][i]);
                }
                m[t]++;
            }
            for (i = 0; i < n; i++)
            {
                if (m.find(grid[i]) != m.end()) ans += m[grid[i]];
            }
            return ans;
        }
};
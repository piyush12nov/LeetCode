class Solution
{
    public:
        long long int mod = 1000000007;
    int ff(int i, int j, vector<vector < int>> &dp, vector< vector< int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int a = 0, b = 0, c = 0, d = 0;
        if (i + 1 < n && grid[i][j] < grid[i + 1][j])
        {
            a = 1 + ff(i + 1, j, dp, grid) % mod;
        }
        if (j + 1 < m && grid[i][j] < grid[i][j + 1])
        {
            b = 1 + ff(i, j + 1, dp, grid) % mod;
        }
        if (i - 1 >= 0 && grid[i][j] < grid[i - 1][j])
        {
            c = 1 + ff(i - 1, j, dp, grid) % mod;
        }
        if (j - 1 >= 0 && grid[i][j] < grid[i][j - 1])
        {
            d = 1 + ff(i, j - 1, dp, grid) % mod;
        }
        return dp[i][j] = ((a + b) % mod + (c + d) % mod) % mod;
    }
    int countPaths(vector<vector < int>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), ans = 0;

        vector<vector < int>> dp(n + 1, vector<int> (m + 1, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = (ans % mod + ff(i, j, dp, grid) % mod) % mod;
            }
        }
        return ans + n * m;
    }
};
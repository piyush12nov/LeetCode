class Solution
{
    public:
        int shortestPathBinaryMatrix(vector<vector < int>> &grid)
        {
            int n = grid.size();
            if (n == 1 && grid[0][0] == 0) return 1;
            if (grid[0][0] == 1) return -1;
            if (grid[n - 1][n - 1] == 1) return -1;
            queue<pair<int, pair<int, int>>> q;
            q.push({ 1,{ 0,0 } });
            int x[] = { 0,0,1,-1,1,1,-1,-1 };
            int y[] = { 1,-1,0,0,1,-1,1,-1 };
            while (!q.empty())
            {
                auto it = q.front();
                q.pop();
                int d = it.first;
                int xx = it.second.first;
                int yy = it.second.second;
                
                for (int i = 0; i < 8; i++)
                {
                    int r = xx + x[i], c = yy + y[i];
                    if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != 0) continue;
                        if(r==n-1&&c==n-1)return d+1;
                        grid[r][c] = d + 1;
                        q.push({ d + 1,{r,c } });
                    
                }
            }
            if (grid[n - 1][n - 1] == 0) return -1;
            return grid[n - 1][n - 1];
        }
};
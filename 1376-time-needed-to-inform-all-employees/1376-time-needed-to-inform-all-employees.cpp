class Solution
{
    public:

        int numOfMinutes(int n, int headID, vector<int> &man, vector<int> &intm)
        {
            int ans = 0, cost ;
            vector<int> adj[n];
            vector<int> vis(n, 0);
            for (int i = 0; i < n; i++)
            {
                if (man[i] == -1) continue;
                adj[man[i]].push_back(i);
            }
            queue<pair<int, int>> q;
            q.push({ headID, 0});
            while (!q.empty())
            {
                auto ne = q.front();
                int node = ne.first;
                int ss = ne.second;
                ans = max(ss, ans);
                q.pop();
                for (auto x: adj[node])
                {
                    cost = intm[man[x]];
                    q.push({ x,cost + ss });
                }
            }
            return ans;
        }
};
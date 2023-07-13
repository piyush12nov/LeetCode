class Solution
{
    public:
        vector<string> findAllRecipes(vector<string> &rec, vector<vector< string >> &ing, vector< string > &supp)
        {
            unordered_map<string, int> m;
            vector<string>ans;
            for (auto x: supp) m[x]++;
            int pre = -1;
            int n = rec.size();
            vector<int>vis(n,0);
            bool f = true;
            while (f)
            {
                f = false;
                for (int i = 0; i < n; i++)
                {
                    int cnt = 0;
                    bool tt = true;
                    if(vis[i])continue;
                    for (auto x : ing[i])
                    {
                        if (m[x] == 0)
                        {
                            tt=false;
                            break;
                        }
                    }
                    if (tt)
                    {
                        f = true;
                        m[rec[i]]++;
                        vis[i]=1;
                        ans.push_back(rec[i]);
                    }
                }
                pre = m.size();
            }
            return ans;
        }
};
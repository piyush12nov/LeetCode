class Solution
{
    public:
    void ff(int i, vector<int> &a, int k,int n, vector<vector < int>> &ans)
    {
        if (k == 0)
        {
            ans.push_back(a);
            return;
        }
        if (i >= n) return;
        for(int j=i+1;j<=n;j++){
       a.push_back(j);
            ff(j, a, k - 1,n,ans);
            a.pop_back();
    }
        
    }
    vector<vector < int>> combine(int n, int k)
    {
 vector<vector < int>> ans;
        vector<int> a;
        ff(0, a, k,n,ans);
        return ans;
    }
};
class Solution {
public:
    int dp[605][103][103];
    int ff(int i,int m,int n,vector<pair<int,int>>&v)
    {
        if(i>=v.size())
        {
            return 0;
        }
      
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int a=0;
        if(m-v[i].first>=0&&n-v[i].second>=0)
         a=1+ff(i+1,m-v[i].first,n-v[i].second,v);
        int b=ff(i+1,m,n,v);
        return dp[i][m][n]=max(a,b);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int>>v;
        for(auto x:strs)
        {
            int one=0;
            for(auto it:x)
            {
                if(it=='0')one++;
            }
            v.push_back({one,x.size()-one});
        }
        return ff(0,m,n,v);
    }
};
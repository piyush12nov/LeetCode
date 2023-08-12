class Solution {
public:
    int dp[104][104];
    int n,m;
    int ff(int i,int j,vector<vector<int>>&v)
    {
        if(i>=n||j>=m||i<0||j<0||v[i][j]==1)return 0;
        if(i==n-1&&j==m-1)return dp[i][j]=1;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=ff(i+1,j,v);
        int c=ff(i,j+1,v);
        return dp[i][j]=a+c;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        n=v.size();
        m=v[0].size();
        memset(dp,-1,sizeof(dp));
        return ff(0,0,v);
    }
};
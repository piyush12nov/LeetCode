class Solution {
public:
    int dp[205][205];
    int n,m;
    int ff(int i,int j,int prev,vector<vector<int>>&v)
    {
        if(i<0||j<0||i>=n||j>=m)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=0,b=0,c=0,d=0;
        if(i+1<n&&v[i+1][j]>prev)
        {
            a=1+ff(i+1,j,v[i+1][j],v);
        }
        if(j+1<m&&v[i][j+1]>prev)
        {
            b=1+ff(i,j+1,v[i][j+1],v);
        }
        if(i-1>=0&&v[i-1][j]>prev)
        {
            c=1+ff(i-1,j,v[i-1][j],v);
        }
        if(j-1>=0&&v[i][j-1]>prev)
        {
            d=1+ff(i,j-1,v[i][j-1],v);
        }
        return dp[i][j]=max({a,b,c,d});
            
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        n=matrix.size();
        m=matrix[0].size();
        int i,j,ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                ans=max(ans,1+ff(i,j,matrix[i][j],matrix));
            }
        }
        return ans;
    }
};
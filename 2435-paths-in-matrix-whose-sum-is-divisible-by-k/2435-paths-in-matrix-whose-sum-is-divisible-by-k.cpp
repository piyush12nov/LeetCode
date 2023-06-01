class Solution {
public:
  //  int dp[50005][50005][51];
  //  map<pair<int,pair<int,int>>,int>dp;
    int k,n,m;
    long long int mod=1000000007;
    int df(vector<vector<int>>&grid,int i,int j,int sum,vector<vector<vector<int>>>&dp)
    {
        if(i>=n||j>=m)return 0;
        if(dp[i][j][sum]!=-1)return dp[i][j][sum];
        if(i==n-1&&j==m-1)
        {
            if((sum+grid[n-1][m-1])%k==0)return 1;
            return 0;
        }
        int a=df(grid,i,1+j,(sum+grid[i][j])%k,dp)%mod;
        int b=df(grid,i+1,j,(sum+grid[i][j])%k,dp)%mod;
        return  dp[i][j][sum]=(a+b)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int kk) {
   
        k=kk;
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1, vector<int> (k+1, -1)));

        return df(grid,0,0,0,dp);
    }
};
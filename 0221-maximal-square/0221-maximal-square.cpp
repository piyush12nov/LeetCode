class Solution {
public:
    int dp[304][304],n,m,ans=0;
    int ff(int i,int j,vector<vector<char>>&mat)
    {
        if(i<0||j<0||i>=n||j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=ff(i+1,j,mat);
        int b=ff(i+1,j+1,mat);
        int c=ff(i,j+1,mat);
        int d=0;
        if(mat[i][j]=='1')
        {
            d=1+min(a,min(b,c));
            ans=max(ans,d);
        }
        return dp[i][j]=d;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp,-1,sizeof(dp));
        n=matrix.size();
        m=matrix[0].size();
         ff(0,0,matrix);
        return ans*ans;
    }
};
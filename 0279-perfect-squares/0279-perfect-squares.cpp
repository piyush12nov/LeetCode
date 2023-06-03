class Solution {
public:
    int dp[10005];
    int fg(int n)
    {
        if(n==0)
        {
            return 0;
        }
        if(dp[n]!=-1)return dp[n];
       
        int c=INT_MAX;
        
        for(int i=1;i<=105;i++)
        {
            if(n-i*i>=0)
            {
                c=min(c,1+fg(n-i*i));
            }
        }
       return dp[n]=c;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return fg(n);
    }
};
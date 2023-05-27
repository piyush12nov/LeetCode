class Solution {
public:
    int dp[105][300];
    int n;
    int df(vector<int>&a,int i,int m,int sum)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i][m]!=-1)return dp[i][m];
        int x=0,cur=0;
        for(int j=i;j<i+2*m;j++)
        {
            if(j<n){
                cur+=a[j];
                x=max(x,sum-df(a,j+1,max(m,j-i+1),sum-cur));
            }
        }
        return dp[i][m]=x;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        n=piles.size();
        int sum=0;
        for(auto x:piles)sum+=x;
        return df(piles,0,1,sum); 
    }
};
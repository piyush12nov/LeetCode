class Solution {
public:
    int dp[1005];
    int ff(int i,vector<int>&co)
    {
        if(i>=co.size())return 0;
        if(dp[i]!=-1)return dp[i];
        
        int c=co[i]+ff(i+1,co);
        c=min(c,co[i]+ff(i+2,co));
        return dp[i]=c;
        }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(ff(0,cost),ff(1,cost));
    }
};
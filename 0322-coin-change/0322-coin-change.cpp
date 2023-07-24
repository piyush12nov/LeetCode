class Solution {
public:
    int dp[10005];
    int ff(int s,vector<int>&co)
    {
        if(s==0)return 0;
        if(dp[s]!=-1)return dp[s];
        int a=100000;
        for(int i=0;i<co.size();i++)
        {
            if(co[i]<=s)
            {
                a=min(a,1+ff(s-co[i],co));
            }
        }
        return dp[s]=a;
    }
    int coinChange(vector<int>& co, int amount) {
//         int n=co.size(),v=amount;
//          long long int dp[v+1],i,j,ss;
// 	    for(i=0;i<=v;i++)dp[i]=INT_MAX;
// 	    dp[0]=0;
// 	    for(i=0;i<=v;i++)
// 	    {
// 	        for(j=0;j<n;j++)
// 	        {
// 	            if(co[j]<=i)
// 	            {
// 	                dp[i]=min(dp[i],dp[i-co[j]]+1);
// 	            }
// 	        }
// 	    }
// 	    if(dp[v]==INT_MAX)return -1;
// 	    return dp[v];
        memset(dp,-1,sizeof(dp));
	    int f = ff(amount,co);
        if(f == 100000)return -1;
        return f;
    }
};
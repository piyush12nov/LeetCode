#define ll long long int
class Solution {
public:
    long long int mod = 1e9+7;
    int dp[500][500];
    int ff(int num,int pre,int x)
    {
        if(num==0)return 1;
        if(num<0||pre<=0)return 0;
        if(dp[num][pre]!=-1)return dp[num][pre];
        ll z=pow(pre,x);
        int pick=0;
        if(num-z>=0)
         pick=ff(num-z,pre-1,x);
        int not_pick=ff(num,pre-1,x);
        return dp[num][pre]=(pick%mod+not_pick%mod)%mod;
    }
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        return ff(n,n,x);
    }
};
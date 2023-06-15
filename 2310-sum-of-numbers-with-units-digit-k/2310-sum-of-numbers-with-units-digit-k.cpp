class Solution {
public:
    int dp[3005];
    int ff(int k,int sum)
    {
        if(sum==0)return 0;
        if(sum<0)return INT_MAX;
        if(dp[sum]!=-1)return dp[sum];
        int aa=100000;
        for(int i=k;i<=sum;i+=10)
        {
            if(sum>=i&&i!=0)
            {
                aa=min(aa,1+ff(k,sum-i));
            }
        }
        return dp[sum]=aa;
    }
    int minimumNumbers(int num, int k) {
        memset(dp,-1,sizeof(dp));
        int tt=ff(k,num);
        if(tt==100000)return -1;
        return tt;
    }
};
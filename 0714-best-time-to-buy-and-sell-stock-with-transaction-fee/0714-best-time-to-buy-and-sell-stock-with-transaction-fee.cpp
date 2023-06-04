class Solution {
public:
    int dp[50005][3];
    int n,fee;
    int ff(int i,int prev,int type,vector<int>&a)
    {
        if(i==n)return 0;
        if(dp[i][type]!=-1)return dp[i][type];
        int ab=0,b=0,c=0;
        if(type==0)
        {
            ab=-1*a[i]-fee+ff(i+1,a[i],1,a);
        }
        if(type==1)
        {
            b=a[i]+ff(i+1,0,0,a);
        }
        c=ff(i+1,prev,type,a);
        return dp[i][type]=max({ab,b,c});
    }
    int maxProfit(vector<int>& a, int feee) {
        n=a.size();
        fee=feee;
        memset(dp,-1,sizeof(dp));
        return ff(0,0,0,a);
    }
};
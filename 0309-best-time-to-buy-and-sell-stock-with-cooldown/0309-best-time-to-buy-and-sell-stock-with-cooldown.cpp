class Solution {
public:
    // int dp[5005][1005][3];   time comp= n*max_element*type; correct
    // int ff(int i,int prev,vector<int>&v,int type)
    // {
    //     if(i>=v.size())return 0;
    //     if(dp[i][prev][type]!=-1)return dp[i][prev][type];
    //     int a=0,b=0,c=0;
    //     if(type==0)
    //     {
    //         a=ff(i+1,v[i],v,1);
    //     }
    //     if(type==1&&v[i]>=prev)
    //     {
    //         b=v[i]-prev+ff(i+2,0,v,0);
    //     }
    //     c=ff(i+1,prev,v,type);
    //     return dp[i][prev][type]=max({a,b,c});
    // }
    int dp[5005][3];
    int n;
    int ff(int i,int type,vector<int>&a)
    {
        if(i>=n)return 0;
        if(dp[i][type]!=-1)return dp[i][type];
        int ab=0,c=0;
        if(type==0)
        {
            ab=-1*a[i]+ff(i+1,1,a);
        }
        if(type==1)
        {
            ab=a[i]+ff(i+2,0,a);
        }
        c=ff(i+1,type,a);
        return dp[i][type]=max({ab,c});
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        n=prices.size();
        return ff(0,0,prices);
    }
};
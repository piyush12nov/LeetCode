class Solution {
public:
    int dp[5005][1005][3];
    int ff(int i,int prev,vector<int>&v,int type)
    {
        if(i>=v.size())return 0;
        if(dp[i][prev][type]!=-1)return dp[i][prev][type];
        int a=0,b=0,c=0;
        if(type==0)
        {
            a=ff(i+1,v[i],v,1);
        }
        if(type==1&&v[i]>=prev)
        {
            b=v[i]-prev+ff(i+2,0,v,0);
        }
        c=ff(i+1,prev,v,type);
        return dp[i][prev][type]=max({a,b,c});
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return ff(0,0,prices,0);
    }
};
class Solution {
public:
    int dp[23][5005];
    int ff(int i,int a,int b,vector<int>&v)
    {
        if(i==v.size())
        {
            if(a==b)return 0;
            else return -1*99999;
        }
        if(dp[i][abs(a-b)]!=-1)return dp[i][abs(a-b)];
        int x=v[i]+ff(i+1,a+v[i],b,v);
        int y=v[i]+ff(i+1,a,b+v[i],v);
        int z=ff(i+1,a,b,v);
        return dp[i][abs(a-b)]=max({x,y,z});
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        return ff(0,0,0,rods)/2;
    }
};
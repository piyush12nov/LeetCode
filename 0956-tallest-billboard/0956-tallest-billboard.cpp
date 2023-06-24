class Solution {
public:
    int dp[23][5005];
    int ff(int i,int a,int b,vector<int>&v,vector<int>&pre)
    {
        if(i==v.size())
        {
            if(a==b)return 0;
            else return -1*99999;
        }
        
        if(dp[i][abs(a-b)]!=-1)return dp[i][abs(a-b)];
        int x=v[i]+ff(i+1,a+v[i],b,v,pre);
        int y=v[i]+ff(i+1,a,b+v[i],v,pre);
        int z=ff(i+1,a,b,v,pre);
        return dp[i][abs(a-b)]=max({x,y,z});
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        vector<int>pre;
        return ff(0,0,0,rods,pre)/2;
    }
};
class Solution {
public:
    int dp[1005][3];
    int ff(int i,int type,vector<int>&a,int prev)
    {
        int n=a.size();
        
        if(i>=n)return 0;
        if(dp[i][type]!=-1)return dp[i][type];
        
        int aa=0,b=0,x=0,y=0,z=0;
        
        if(type==0&&prev<a[i])
        {
            x=ff(i+1,1,a,a[i]);

       //     cout<<i<<" "<<prev<<" "<<type<<endl;
            aa=1+x;
        }
        if(type==1&&prev>a[i])
        {
            y=ff(i+1,0,a,a[i]);
        //    cout<<i<<" "<<prev<<" "<<type<<endl;
            b=1+y;
        }
        if(type==0)y=ff(i+1,0,a,a[i]);
        if(type==1)x=ff(i+1,1,a,a[i]);
        z=ff(i+1,type,a,prev);
        
        dp[i][type]=max({aa,x,b,y,z});
        
        return dp[i][type];
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int aa1=ff(0,0,nums,0);
        memset(dp,-1,sizeof(dp));
        int aa2=ff(0,1,nums,1001);
        return max(aa1,aa2);
    }
};
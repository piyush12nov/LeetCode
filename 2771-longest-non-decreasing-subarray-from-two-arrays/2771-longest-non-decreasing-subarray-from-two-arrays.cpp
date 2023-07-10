class Solution {
public:
    int dp[100005][3];
    int ff(int i,vector<int>&a,vector<int>&b,int tp)
    {
        int n=a.size();
        if(i>=n)return 0;
        if(dp[i][tp]!=-1)return dp[i][tp];
        int ans=0;
        if(tp==0)
        {
               ans=max(ans,1+ff(i+1,a,b,1));
            ans=max(ans,1+ff(i+1,a,b,2));
        ans=max(ans,ff(i+1,a,b,0));
        }
       else if(tp==1){
                     

        if(a[i-1]<=a[i])
        {
            ans=max(ans,1+ff(i+1,a,b,1));
        }
        if(a[i-1]<=b[i])
        {
            ans=max(ans,1+ff(i+1,a,b,2));
        }
            }
    else
        {
            if(b[i-1]<=a[i])
            {
                ans=max(ans,1+ff(i+1,a,b,1));
            }
            if(b[i-1]<=b[i])
            {
                ans=max(ans,1+ff(i+1,a,b,2));
            }
        }
        return dp[i][tp]=ans;
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return ff(0,nums1,nums2,0);
    }
};
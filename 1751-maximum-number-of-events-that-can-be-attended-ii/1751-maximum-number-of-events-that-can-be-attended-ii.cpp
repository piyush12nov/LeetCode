#define ll long long int
class Solution {
public:
    vector<int>v;
    bool static cmp(vector<int>&p,vector<int>&q)
    {
        if(p[0]==q[0])return p[1]<q[1];
        return p[0]<q[0];
    }
    int ff(int i,int k,int n ,vector<vector<int>>&a,vector<vector<int>>&dp)
    {
        if(i>=n||k<=0)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int aa=0,b=0,cc=0;
        int j=upper_bound(v.begin(),v.end(),a[i][1])-v.begin();
            
        aa=a[i][2]+ff(j,k-1,n,a,dp);
        
        b=ff(i+1,k,n,a,dp);
        return dp[i][k]=max(aa,b);
    }
    int maxValue(vector<vector<int>>& a, int k) {
        int n = a.size(),ans=0;
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        sort(a.begin(),a.end(),cmp);
        for(auto x:a)
        {
            v.push_back(x[0]);
        }
       
        return ff(0,k,n,a,dp);
    }
};
class Solution {
public:
    int dp[100005];
    int n,dif;
    int ff(int i,int val,map<int,vector<int>>&m)
    {
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int a=0,b=0,c=0;
        for(auto x:m[val])
        {
            if(x>=i)
            a=max(a,1+ff(x,val+dif,m));
        }
        return dp[i]=a;
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,vector<int>>m;
        memset(dp,-1,sizeof(dp));
        int ans=0;
        n=arr.size();
        dif=difference;
        int gg=0;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]].push_back(i);
            gg=max(gg,(int)m[arr[i]].size());
        }
        if(dif==0)return gg;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,ff(i,arr[i],m));
        }
        return ans;
    }
};
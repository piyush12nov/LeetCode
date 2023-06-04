class Solution {
public:
    int dp[1005][3000];
    int n;
    int ff(int i,vector<vector<int>>&v,int prev)
    {
        if(i==n)return 0;
        if(dp[i][prev]!=-1)return dp[i][prev];
        int a=0,b=0;
        if(v[i][0]+1000>prev)
        {
            a=1+ff(i+1,v,v[i][1]+1000);
        }
        b=ff(i+1,v,prev);
        return dp[i][prev]=max(a,b);
    }
    
    int findLongestChain(vector<vector<int>>& pai) {
        sort(pai.begin(),pai.end());
        memset(dp,-1,sizeof(dp));
        n=pai.size();
        return ff(0,pai,0);
    }
};
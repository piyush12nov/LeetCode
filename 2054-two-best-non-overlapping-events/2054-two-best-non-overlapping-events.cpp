class Solution {
public:
    int dp[100005][3];
    vector<int>start;
    int n;
    int ff(int i,vector<vector<int>>&a,int k)
    {
        if(i>=n||k==0)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int j=upper_bound(start.begin(),start.end(),a[i][1])-start.begin();
        return dp[i][k]=max(a[i][2]+ff(j,a,k-1),ff(i+1,a,k));
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n=events.size();
        memset(dp,-1,sizeof(dp));
        sort(events.begin(),events.end());
        for(auto x:events)start.push_back(x[0]);
        return ff(0,events,2);
    }
};
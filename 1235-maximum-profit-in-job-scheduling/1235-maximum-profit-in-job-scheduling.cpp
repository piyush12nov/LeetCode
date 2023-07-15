class Solution
{
    public:
    int dp[100005];
    int n;
    vector<int>st;
    int ff(int i,vector<vector<int>>&a)
    {
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int j=lower_bound(st.begin(),st.end(),a[i][1])-st.begin();
        int x = a[i][2]+ ff(j,a);
        int y = ff(i+1,a);
        return dp[i]=max(x,y);
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector< int > &profit)
    {

        n = startTime.size();
        memset(dp,-1,sizeof(dp));
        vector<vector < int>> jobs(n, vector<int> (3));

        for (int i = 0; i < n; i++)
        {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        sort(jobs.begin(), jobs.end());
        for(auto x:jobs)st.push_back(x[0]);
        return ff(0, jobs);
    }
};
class Solution {
public:
    bool static cmp(vector<int>&p,vector<int>&q)
    {
        if(p[0]==q[0])return p[1]>q[1];
        return p[0]<q[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),cmp);
        int ans=0,n=a.size();
        for(auto x:a)
        {
            cout<<x[0]<<" "<<x[1]<<endl;   
        }
        for(int i=0;i<n;i++)
        {
            int st=a[i][0],end=a[i][1];
            ans++;
            while(i+1<n&&st<=a[i+1][0]&&end>=a[i+1][1])i++;
            
        }
        return ans;
    }
};
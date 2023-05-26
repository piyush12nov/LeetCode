class Solution {
public:
    bool static cmp(pair<int,int>&p1,pair<int,int>&p2)
    {
        if(p1.first==p2.first)return p1.second>p2.second;
        return p1.first>p2.first;
    }
    vector<int> filterRestaurants(vector<vector<int>>& a, int sabji, int price, int dist) {
        int i,j,n=a.size(),flag;
        vector<int>res;
        if(sabji==0)flag=1;
        else flag=2;
        for(i=0;i<n;i++)
        {
            if(flag==1)
            if(a[i][3]<=price&&a[i][4]<=dist)
            {
                res.push_back(i);
            }
            if(flag==2)
            {
                if(a[i][2]==sabji&&a[i][3]<=price&&a[i][4]<=dist)
                {
                res.push_back(i);
                }
            }
            // else if(a[i][3]==price)
            // {
            //     res.push_back(i);
            // }
            // else if(a[i][4]==dist)
            // {
            //     res.push_back(i);
            //}
        }
        vector<pair<int,int>>v;
        for(auto x:res)
        {
            v.push_back({a[x][1],a[x][0]});
        }
        sort(v.begin(),v.end(),cmp);
        res.clear();
        for(auto x:v)
        {
            res.push_back(x.second);
        }
        return res;
    }
};
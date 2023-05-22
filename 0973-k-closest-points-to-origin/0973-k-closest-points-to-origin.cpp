class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        for(auto e:points)
        {
            int x=e[0],y=e[1];
            pq.push({x*x+y*y,{x,y}});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<vector<int>>ans(k);
        int i=k-1;
        while(!pq.empty())
        {
            ans[i].push_back(pq.top().second.first);
            ans[i].push_back(pq.top().second.second);
            pq.pop();
            i--;
        }
        return ans;
    }
};
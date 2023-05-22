class Solution {
public:
    bool static cmp(pair<int,string>&p1,pair<int,string>&p2)
    {
        if(p1.first==p2.first)
        {
            return p1.second<p2.second;
        }
        return p1.first>p2.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>m;
        for(auto x:words)m[x]++;
        vector<string>ans(k);
        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(cmp)*>pq(&cmp);
        for(auto [a,b]:m)
        {
            if(pq.size()>=k)
            {
                if(pq.top().first<b||(pq.top().first==b&&pq.top().second>a))
                {
                    pq.pop();
                    pq.push({b,a});
                }
            }
            else
                pq.push({b,a});
        }
        int i=k-1;
        while(!pq.empty()&&k)
        {
            ans[i]=pq.top().second;
            pq.pop();
            i--;
            k--;
        }
        return ans;
        
    }
};
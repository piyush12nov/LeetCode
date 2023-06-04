class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n=nums.size(),an=0,ans=INT_MAX;
        unordered_map<int, int>m,ma;
        for(auto x:nums)
        {
            m[x%space]++;
            if(ma.find(x%space)==m.end())ma[x%space]=x;
            ma[x%space]=min(ma[x%space],x);
        }
        for(auto x:m)
        {
            if(an<x.second)
            {
                ans=ma[x.first];
                an=x.second;
            }
            else if(an==x.second)
            {
                ans=min(ma[x.first],ans);
            }

        }
        return ans;
    }
};
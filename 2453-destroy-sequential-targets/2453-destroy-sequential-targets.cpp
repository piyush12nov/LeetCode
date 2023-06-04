class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n=nums.size(),an=0,ans=INT_MAX;
        unordered_map<int, int>m;
        for(auto x:nums)
        {
            m[x%space]++;
             an=max(an,m[x%space]);
        }
        for(auto x:nums)
        {
            if(an==m[x%space])
            {
                ans=min(x,ans);
            }
        }
        return ans;
    }
};
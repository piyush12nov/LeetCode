class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int,int>m;
        int ans=0,res=nums[0],result=INT_MAX;
       
        for(auto x:nums)
        {
            m[x%space]++;
            if(ans<m[x%space])
            {
                ans=max(ans,m[x%space]);   
            }
        }
        for(int i = 0; i < nums.size() ; i++)
        {
            if(m[nums[i]%space]==ans)
            {
                result=min(result,nums[i]);
            }
        }
        return result;
    }
};
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),le=1;
        vector<int>dp(n,1),count(n,1);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[j]+1>dp[i])
                    {
                        count[i]=count[j];
                        dp[i]=dp[j]+1;
                    }
                    else if(dp[j]+1==dp[i])
                    {
                        count[i]+=count[j];
                    }
                }
            }
            le=max(le,dp[i]);
        }
        int ans=0;
       
      
        for(int i=0;i<nums.size();i++)
        {
            if(dp[i]==le)
            {
                ans+=count[i];
            }
        }
       
        return ans;
    }
};
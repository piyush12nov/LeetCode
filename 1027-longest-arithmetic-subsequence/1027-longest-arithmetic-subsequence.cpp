class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        int i,n=nums.size(),j;
        int ma=*max_element(nums.begin(),nums.end());
        vector<vector<int>>dp(nums.size()+1,vector<int>(505+ma,1));
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                int ss=500+nums[i]-nums[j];
                dp[i][ss]=max(dp[i][ss],dp[j][ss]+1);
            }
        }
        int ans=0;
        for(auto x:dp)
        {
            for(auto it:x)ans=max(ans,it);
        }
        return ans;
    }
};
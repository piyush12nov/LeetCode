class Solution {
public:
    int dp[305][5003];
    int ff(int k,int i,vector<int>&nums)
    {
        if(k==0)
        {
            return 1;
        }
        if(i>=nums.size()||k<0)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int a=ff(k-nums[i],i,nums);
        int b=ff(k,i+1,nums);
        return dp[i][k]=a+b;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));

        int a= ff(amount,0,coins);        
        return a;
    }
};
class Solution
{
    public:
        long long int mod = 1000000007;
        int numberOfGoodSubarraySplits(vector<int> &nums)
        {
            int ans = 1, pre = 0, ttt = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                pre += nums[i];
                if (pre>1&&nums[i]==1)
                {
                    ans = ((ans%mod)*(ttt%mod))%mod;
                    ans = ans%mod;
                    ttt = 0;
                }
                if(pre>0)
                ttt++;
            }
            if(pre==0)return 0;
            return ans;
        }
};
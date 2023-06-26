class Solution
{
    public:
        long long int mod = 1000000007;
        int numberOfGoodSubarraySplits(vector<int> &nums)
        {
            int ans = 1, pre = 0;
            unordered_map<int, int> m;
            for (int i = 0; i < nums.size(); i++)
            {
                pre += nums[i];
                if (pre>1&&nums[i]==1)
                {
                    ans = ((ans%mod)*(m[pre-1]%mod))%mod;
                    ans = ans%mod;
                }
                m[pre]++;
            }
            if(pre==0)return 0;
            return ans;
        }
};
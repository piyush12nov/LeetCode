class Solution
{
    public:
        vector<int> smallerNumbersThanCurrent(vector<int> &nums)
        {
            int n = nums.size();
            unordered_map<int, int> m;
            vector<int> cnt(101, 0), ans(n);
            for (auto x: nums)
            {
                m[x]++;
            }
            int prev = 0, x = 0;
            for (int i = 0; i <= 100; i++)
            {
                cnt[i] = x + prev;
                if (m[i] > 0)
                {
                    x = x + prev;
                    prev = m[i];
                }
            }
            for (int i = 0; i < n; i++)
            {
                ans[i] = cnt[nums[i]];
            }
            return ans;
        }
};
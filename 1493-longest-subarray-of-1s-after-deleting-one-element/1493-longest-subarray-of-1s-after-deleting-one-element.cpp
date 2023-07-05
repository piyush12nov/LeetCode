class Solution
{
    public:
        int longestSubarray(vector<int> &a)
        {
            int n = a.size(), i = 0, prev = 0, ans = 0, zero = 0, one = 0;
            while (i < n)
            {
                zero = 0;
                one = 0;
                if (a[i] == 0)
                {
                    while (i < n && a[i] == 0)
                    {
                        i++;
                        zero++;
                    }
                }
                if (i < n && a[i] == 1)
                {
                    while (i < n && a[i] == 1)
                    {
                        i++;
                        one++;
                    }
                    if (one != n) ans = max(ans, one);
                    if (zero == 1)
                    {
                        ans = max(ans, prev + one);
                    }
                    else if (zero == 0) ans = max(ans, prev + one - 1);
                    prev = one;
                }
            }
            return ans;
        }
};
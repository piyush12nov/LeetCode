class Solution
{
    public:
        int dp[104];
    int ff(int i, string s)
    {
        int n = s.size();
        if (i >= n) return 1;
        if (dp[i] != -1) return dp[i];
        int a = 0, b = 0;
        if (s[i] != '0')
        {
            a = ff(i + 1, s);
            if (i + 1 < n)
            {
                int x = (s[i] - '0') *10 + s[i + 1] - '0';
                if (i + 1 < n && x <= 26)
                    b = ff(i + 2, s);
            }
        }
        return dp[i] = a + b;
    }
    int numDecodings(string s)
    {
        memset(dp, -1, sizeof(dp));
        return ff(0, s);
    }
};
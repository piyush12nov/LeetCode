class Solution
{
    public:
    bool palin(string &s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    int ff(int i, string &s, int n, vector<int>&dp)
    {
        if (i == s.size())
        {
            return 0;
        }
        if (dp[i] != -1) return dp[i];
        int a = 9999;
        string re;
        for (int j = i; j < s.size(); j++)
        {
            re += s[j];
            if (palin(re))
            {
                a = min(a, 1 + ff(j + 1, s, n, dp));
            }
        }
        return dp[i] = a;
    }
    int minCut(string s)
    {
        vector<int>dp(s.size()+1,-1);
        return ff(0, s, s.size(), dp)-1;
    }
};
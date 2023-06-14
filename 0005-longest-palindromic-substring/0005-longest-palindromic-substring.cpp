class Solution
{
    public:
        bool isPalin(string & s)
        {
            int l = 0, r = s.size() - 1;
            while (l < r)
            {
                if (s[l] == s[r])
                {
                    l++;
                    r--;
                }
                else return 0;
            }
            return true;
        }
    string longestPalindrome(string & s)
    {
        vector<string> v;
        string ans = "";
        int curr = 0;
        for (int i = 0; i < s.size(); i++)
        {
            string g = "";
            string f = "";
            for (int j = 0; j <= i; j++)
            {
                g += s[j];
                if (isPalin(g))
                {
                    int si = g.size();
                    if (si > curr)
                    {
                        ans = g;
                        curr = si;
                    }
                }
            }
            for (int j = i + 1; j < s.size(); j++)
            {
                f += s[j];
                if (isPalin(f))
                {
                    int si = f.size();
                    if (si > curr)
                    {
                        ans = f;
                        curr = si;
                    }
                }
            }
        }

        return ans;
    }
};
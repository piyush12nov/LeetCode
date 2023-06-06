class Solution
{
    public:
        string evaluate(string s, vector<vector < string>> &knowledge)
        {
            int i, n = s.size();
            map<string, string> m;
            string ans;
            for (auto x: knowledge)
            {
                m[x[0]] = x[1];
            }
            for (i = 0; i < n; i++)
            {
                string ss;
                if (s[i] == '(')
                {
                    i++;
                    while (s[i] != ')' && i < n)
                    {
                        ss = ss + s[i];
                        i++;
                    }
                    if (m.find(ss) != m.end()) ans += m[ss];
                    else ans += '?';
                }
                else
                {
                    ans += s[i];
                }
            }
            return ans;
        }
};
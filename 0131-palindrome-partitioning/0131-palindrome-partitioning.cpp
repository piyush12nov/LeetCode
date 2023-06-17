class Solution
{
    public:
        vector<vector < string>> ans;
    int n;
    bool palin(string s)
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
    void ff(int i, vector<string>& v, string &s)
    {
        if (i == s.size())
        {
            ans.push_back(v);
            return;
        }
        string re;
        for (int j = i; j < n; j++)
        {

            re += s[j];
            if (palin(re))
            {
                v.push_back(re);
                ff(j + 1, v, s);
                v.pop_back();
            }
        }
    }
    vector<vector < string>> partition(string s)
    {
        vector<string> v;
        n = s.size();
        ff(0, v, s);
        return ans;
    }
};
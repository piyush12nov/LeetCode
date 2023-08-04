class Solution
{
	public:
		set<string> sw;
    vector<string>ans;
	void ff(int i, int n, string s, int cnt,string sp)
	{
		
        if(cnt==n)
        {
            sp.pop_back();
            ans.push_back(sp);
			return ;
        }
        if (i == n)
		{
            return ;
		}

		
        string temp = "";
		
        for (int j = i; j < n; j++)
		{
			temp += s[j];

			if (sw.find(temp) != sw.end())
			{
				 ff(j + 1, n, s, cnt + temp.size(),sp+temp+" ");
			}
		}

		return ;
	}

	vector<string> wordBreak(string s, vector<string> &wordDict)
	{
		for (auto x: wordDict) sw.insert(x);
		int n = s.size();
		ff(0, n, s, 0,"");
		return ans;
	}
};

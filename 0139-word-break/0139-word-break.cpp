class Solution
{
	public:
		set<string> sw;
	bool ans = false;
	map<pair<int, int>, int> dp;
	int ff(int i, set<string> pre, int n, string s, int cnt)
	{
		if (cnt == n)
		{
			ans = true;
			return 1;
		}

		if (ans) return 1;
		
        if (i == n)
		{
			return 0;
		}

		if (dp.find({ i, cnt }) != dp.end()) return dp[{i, cnt}];
		
        string temp = "";
		int as = 0;
		
        for (int j = i; j < n; j++)
		{
			temp += s[j];

			if (sw.find(temp) != sw.end())
			{
				pre.insert(temp);
				as = ff(j + 1, pre, n, s, cnt + temp.size());
				pre.erase(temp);
			}
		}

		return dp[{i, cnt}] = as;
	}

	bool wordBreak(string s, vector<string> &wordDict)
	{
		for (auto x: wordDict) sw.insert(x);
		set<string> pre;
		int n = s.size();
		int y = ff(0, pre, n, s, 0);
		return y;
	}
};

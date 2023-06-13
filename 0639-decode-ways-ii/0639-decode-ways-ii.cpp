class Solution
{
	public:
		int dp[1000005];
	int n;
	long long int m = 1000000007;
	int ff(int i, string &s)
	{
		if (i >= s.size()) return 1;
		if (dp[i] != -1) return dp[i] % m;
		int a = 0, b = 0, d = 0, c = 0;
		if (s[i] == '0') return dp[i] = 0;
		else if (s[i] == '*')
		{
			a = (9 % m *(ff(i + 1, s) % m)) % m;
			if (i + 1 < n)
			{
				if (s[i + 1] != '*')
				{
					if (s[i + 1] > '6')
					{
						b = ff(i + 2, s) % m;
					}
					else if (s[i + 1] <= '9')
					{
						b = (2 % m *(ff(i + 2, s) % m)) % m;
					}
				}
				else if (s[i + 1] == '*')
				{
					c = (15 *(ff(i + 2, s) % m)) % m;
				}
			}
		}
		else if (s[i] != '*')
		{
			a = ff(i + 1, s) % m;
			if (i + 1 < n)
			{
				if (s[i + 1] != '*')
				{
					int x = (s[i] - '0') *10 + s[i + 1] - '0';
					if (x <= 26)
						b = ff(i + 2, s) % m;
				}
				else if (s[i + 1] == '*')
				{
					if (s[i] == '2')
					{
						c = (6 % m *(ff(i + 2, s) % m)) % m;
					}

					if (s[i] == '1')
					{
						d = (9 % m *(ff(i + 2, s) % m)) % m;
					}
				}
			}
		}

		return dp[i] = ((a % m + b % m)%m + (c % m + d % m) % m) % m;
	}

	int numDecodings(string s)
	{
		memset(dp, -1, sizeof(dp));
		n = s.size();
		return ff(0, s);
	}
};

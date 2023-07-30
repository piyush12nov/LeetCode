class Solution
{
	public:

		vector<vector < string>> v;
	bool static cmp(string &a, string &b)
	{
		if (a.size() != b.size()) return a.size() < b.size();
		return a < b;
	}

	void ff(int i, vector<string> &ss)
	{
		int n = ss.size();
		if (i == n - 1)
		{
			v.push_back(ss);
		}

		for (int j = i; j < n; j++)
		{
			swap(ss[j], ss[i]);
			ff(i + 1, ss);
			swap(ss[j], ss[i]);
		}

		return;
	}

	string minimumString(string a, string b, string c)
	{
		vector<string> temp;
		temp.push_back(a);
		temp.push_back(b);
		temp.push_back(c);
		ff(0, temp);
		vector<string> ans;
		for (int i = 0; i < 6; i++)
		{
			string res = v[i][0];
			for (int k = 0; k < 2; k++)
			{
				string temp, st;
				int uy = 0;
				for (int j = 0; j < v[i][k + 1].size(); j++)
					st += v[i][k + 1][j];
				
                if (res.find(st) != string::npos) continue;
				
                for (int j = res.size() - 1; j >= 0; j--)
				{
					temp += res[j];
					
                    reverse(temp.begin(), temp.end());
					auto s = st.find(temp);
					reverse(temp.begin(), temp.end());
					
                    if (s == string::npos || s != 0) continue;

					uy = temp.size();
				}
                res = res + v[i][k+1].substr(uy,v[i][k+1].size()-uy);
			}

			ans.push_back(res);
		}

		sort(ans.begin(), ans.end(), cmp);

		return ans[0];
	}
};

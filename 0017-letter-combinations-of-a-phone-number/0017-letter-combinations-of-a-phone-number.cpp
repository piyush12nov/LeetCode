class Solution
{
	public:
		
    vector<string> ans;
	
    void ss(string s, int index, vector<vector < char>> &v, string temp, int n)
	{
		if (index == n)
		{
			ans.push_back(temp);
			return;
		}

		for (int j = 0; j < v[s[index] - '0'].size(); j++)
		{
			temp.push_back(v[s[index] - '0'][j]);
			ss(s, index + 1, v, temp, n);
			temp.pop_back();
		}

    }

	vector<string> letterCombinations(string digits)
	{
		vector<vector < char>> v(10);
		
        v[2] = { 'a', 'b', 'c' };

		v[3] = { 'd', 'e', 'f' };

		v[4] = { 'g', 'h', 'i' };

		v[5] = { 'j', 'k', 'l' };

		v[6] = { 'm', 'n', 'o' };

		v[7] = { 'p', 'q', 'r', 's' };

		v[8] = { 't', 'u', 'v' };

		v[9] = { 'w', 'x', 'y', 'z' };
		
        if (digits == "")
		{
			return ans;
		}

		ss(digits, 0, v, "", digits.size());
		
        return ans;
	}
};

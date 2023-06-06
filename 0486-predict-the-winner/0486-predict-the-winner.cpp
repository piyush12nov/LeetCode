class Solution
{
	public:
		int dp[21][21];
	int ff(vector<int> &nums, int l, int r, int c)
	{
		if (l > r) return 0;
		if (dp[l][r] != -1) return dp[l][r];

		int lu = nums[l] + min(ff(nums, l + 1, r - 1, c ^ 1), ff(nums, l + 2, r, c ^ 1));
		int ru = nums[r] + min(ff(nums, l + 1, r - 1, c ^ 1), ff(nums, l, r - 2, c ^ 1));

		return dp[l][r] = max(lu, ru);
	}

	bool PredictTheWinner(vector<int> &nums)
	{
		memset(dp, -1, sizeof(dp));
		int n = nums.size(), tot = 0;
		for (auto x: nums) tot += x;
		int frf = ff(nums, 0, n - 1, 1);

		if (frf >= tot - frf) return true;
		return false;
	}
};

class Solution
{
    public:
        vector<vector < int>> ans;
    void ff(int i, vector<int> a)
    {
        if (i == a.size() - 1)
        {
            ans.push_back(a);
            return;
        }

        for (int j = i; j < a.size(); j++)
        {
            if (i != j && a[i] == a[j]) continue;
            swap(a[i], a[j]);
            ff(i + 1, a);
        }
    }
    vector<vector < int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        ff(0, nums);
        return ans;
    }
};
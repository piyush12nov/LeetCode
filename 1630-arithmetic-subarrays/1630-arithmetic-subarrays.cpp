class Solution
{
    public:
        bool ff(vector<int> nums, int l, int r)
        {
            sort(nums.begin() + l, nums.begin() + r + 1);

            for (int i = l; i <= r - 2; i++)
            {
                if (nums[i + 1] - nums[i] != nums[i + 2] - nums[i + 1]) return 0;
            }

            return 1;
        }
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector< int > &r)
    {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++)
        {
            if (ff(nums, l[i], r[i]))
            {
                ans.push_back(true);
            }
            else
                ans.push_back(false);
        }
        return ans;
    }
};
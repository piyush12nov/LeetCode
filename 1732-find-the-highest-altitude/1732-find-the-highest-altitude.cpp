class Solution
{
    public:
        int largestAltitude(vector<int> &a)
        {
            int ans = 0, pre = 0;
            for (int i = 0; i < a.size(); i++)
            {
                pre = pre + a[i];
                ans = max(ans, pre);
            }
            return ans;
        }
};
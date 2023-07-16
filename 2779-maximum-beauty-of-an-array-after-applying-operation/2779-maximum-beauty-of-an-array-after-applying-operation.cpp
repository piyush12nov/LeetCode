class Solution
{
    public:
        bool static cmp(pair<int, int> &p, pair<int, int> &q)
        {
            if (p.first == q.first) return p.second < q.second;
            return p.first < q.first;
        }
    int maximumBeauty(vector<int> &nums, int k)
    {
        vector<pair<int, int>> v;
        for (auto x: nums)
        {
            v.push_back({ x - k,  x + k });
        }
        sort(v.begin(), v.end(), cmp);
        vector<int>sf;
        int i = 0, n = nums.size(), ans = 0;
        for(auto x:v)
        {
            sf.push_back(x.first);
        }
        int hh = 0;
        while (i < n)
        {
            hh = 0;
            int end = v[i].second;
            int j=upper_bound(sf.begin(),sf.end(),end)-sf.begin();
            ans=max(ans,j-i);
            i++;
        }
        return ans;
    }
};
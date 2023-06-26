#define ll long long int
class Solution
{
    public:
        long long totalCost(vector<int> &a, int can, int k)
        {
            ll n = a.size();
            ll l = 0, r = n - 1, ans = 0, flag = 0;
            priority_queue<int, vector < int>, greater < int>> p1, p2;
            while (l < k && l <= r)
            {
                p1.push(a[l]);
                l++;
            }

            while (r >= n - k && l <= r)
            {
                p2.push(a[r]);
                r--;
            }

            while (can)
            {
                ll x = INT_MAX, y = INT_MAX;
                if (p1.size() >= 1)
                    x = p1.top();
                if (p2.size() >= 1)
                    y = p2.top();
                if (x <= y)
                {
                    can--;
                    ans += x;
                    p1.pop();
                    if (l <= r)
                    {
                        p1.push(a[l]);
                        l++;
                    }
                }
                else
                {
                    can--;
                    ans += y;
                    p2.pop();
                    if (l <= r)
                    {
                        p2.push(a[r]);
                        r--;
                    }
                }
            }
            return ans;
        }
};

#define ll long long int
class Solution
{
    public:
        bool aaja(vector<int> &a, double tt, int m)
        {
            double s = 0;
            int n = a.size();
            for (int i = 0; i < n; i++)
            {
                s = ceil(s);
                ll x = a[i];
                s += (double)(x / (double) m);
                if (s > tt) return false;
            }

            return true;
        }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        ll l = 1, r = 1e7, ans;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (aaja(dist, hour, mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if (aaja(dist, hour, ans)&&ans>0&&ans<=1e7) return ans;
        return -1;
    }
};
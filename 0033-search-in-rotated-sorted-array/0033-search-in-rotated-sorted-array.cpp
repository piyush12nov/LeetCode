class Solution
{
    public:
        int search(vector<int> &a, int target)
        {
            int l = 0, r = a.size() - 1, n = a.size(), mid;
            
            if (r == 0 && a[r] == target) return 0;
            if (r == 0 && a[r] != target) return -1;
            int first = a[0];
            int last = a[r];
            int re = -111;
            if (first < last)
            {
                re = r;
            }
            if (a[r - 1] > a[r])
            {
                re = r - 1;
            }
            if (a[0] > a[1])
            {
                re = 0;
            }
            /////////////// FIND LAST INDEX
            while (l <= r && re == -111)
            {
                mid = l + (r - l) / 2;

                if (a[mid - 1] > a[mid] && a[mid + 1] > a[mid])
                {
                    re = mid - 1;
                    break;
                }
                if (a[mid] > last && a[mid] > first)
                {
                    l = mid + 1;
                }
                else if (a[mid] < last && a[mid] < first)
                {
                    r = mid - 1;
                }
            }
            if(re==-111)return -1;
            ////////////////////////////////////////
            // FROM 0 to max
            // ////////////////////////////////////////
            l = 0;
            r = re;
            while (l <= r)
            {
                mid = l + (r - l) / 2;
                if (a[mid] == target) return mid;
                else if (a[mid] < target) l = mid + 1;
                else r = mid - 1;
            }
            //////////////////////////////////////////
            // FROM max+1 to n-1
            //////////////////////////////////////////
            l = re + 1;
            r = n - 1;
            while (l <= r)
            {
                mid = l + (r - l) / 2;
                if (a[mid] == target) return mid;
                else if (a[mid] < target) l = mid + 1;
                else r = mid - 1;
            }
            //////////////////////////////////////////
            return -1;
        }
};
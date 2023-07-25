class Solution
{
    public:
        int findInMountainArray(int target, MountainArray &arr)
        {
            int l = 0, n = arr.length(), flag = 1;
            int r = n-1 , ff;
            while (l <= r )
            {
                int mid = (l + r) / 2;
                int num=arr.get(mid);

                if (mid - 1 >= 0 && mid + 1 < n && arr.get(mid - 1) < num && num > arr.get(mid + 1))
                {
                    ff = mid;
                    break;
                }
                else if (mid-1>=0&&arr.get(mid - 1) > num)
                {
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            l = 0;
            r = ff;
            
            while (l <= r)
            {
                int mid = (l + r) / 2;
                int num=arr.get(mid);
                if (num == target) return mid;
                else if (num < target)
                {
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            l = ff + 1, r = n - 1;
         
            while (l <= r)
            {
                int mid = (l + r) / 2;
                int num=arr.get(mid);
                if (num == target) return mid;
                else if (num < target)
                {
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            return -1;
        }
};
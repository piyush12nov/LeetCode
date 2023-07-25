class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        int n=r;
        if(n==0)return 0;
        if(arr[0]>arr[1])return 0;
        if(arr[n-1]>arr[n-2])return n-1;
        while(l<=r)
        {
            int mid = r + (l-r)/2;
            if(mid-1>=0&&mid+1<=n&&arr[mid-1]<arr[mid]&&arr[mid]>arr[mid+1])
            {
                return mid;
            }
            if(arr[mid]<arr[mid-1])
            {
                r=mid-1;
            }
            else l=mid+1;
        }
        return 0;
    }
};
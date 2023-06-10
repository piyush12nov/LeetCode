#define ll long long int
class Solution {
public:
     static bool ff(long long int x,int idx,int n,long long int maxsum) {
        long long int s = x;
        
        // building the left side of index
        s += (x*(x-1))/2;
        if(idx-1 < x-1) {
            long long diff = x-1-idx+1;
            s -= (diff*(diff+1))/2;
        } else if(idx-1 > x-1) {
            s += idx-1-x+1;
        }

        // building the right side of index
        s += (x*(x-1))/2;
        if(n-idx < x-1) {
            long long diff = x-1-n+idx;
            s -= (diff*(diff+1))/2;
        } else if(n-idx > x-1) {
            s += n-idx-x+1;
        }

        return (s <= maxsum);
    }
    int maxValue(int n, int index, int maxSum) {
        int l=0,r=maxSum,ans=1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(ff(mid,index+1,n,maxSum))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }

        return ans;
    }
};
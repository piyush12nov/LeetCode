class Solution {
public:
    bool ff(long long int a,int n)
    {
        long long int aa=((long long int)a*a+a)/2;
        return (aa<=n);
    }
    int arrangeCoins(int n) {
        int l=1,r=n,ans=1;
        while(l<=r)
        {
            long long int mid=((1LL)*l+r)/2;
            if(ff(mid,n))
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
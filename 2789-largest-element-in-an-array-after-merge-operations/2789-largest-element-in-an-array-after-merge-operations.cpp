class Solution {
public:
    long long maxArrayValue(vector<int>& a) {
        long long n=a.size(),m=0,ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(m>=a[i])
            {
                m=m+a[i];
            }
            else
            {
                m=a[i];
            }
            ans=max(ans,m);
        }
        return ans;
    }
};
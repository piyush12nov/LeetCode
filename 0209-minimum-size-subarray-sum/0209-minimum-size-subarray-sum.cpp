class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& a) {
        int l=0,r=0,n=a.size(),ans=INT_MAX;
        int sum=0;
        while(l<n&&r<n)
        {
            sum+=a[r];
         
            while(sum>=tar)
            {
                sum-=a[l];
                ans=min(ans,r-l+1);
                l++;
            }

            r++;
        }
        return ans==INT_MAX?0:ans;
    }
};
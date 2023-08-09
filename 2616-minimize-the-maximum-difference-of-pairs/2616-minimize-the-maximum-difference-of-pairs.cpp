class Solution {
public:
    bool fun(vector<int>&a,int p,int mid)
    {
        int cnt=0;
        for(int i=0;i+1<a.size();i++)
        {
            if(a[i+1]-a[i]<=mid)
            {
                i++;
                cnt++;
            }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int l=0,r=1e9,ans;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(fun(nums,p,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
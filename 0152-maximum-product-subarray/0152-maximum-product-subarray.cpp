class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=*max_element(nums.begin(),nums.end()),n=nums.size(),i,x=1;
        for(i=0;i<n;i++)
        {
           x=x*nums[i];
            ans=max(ans,x);
            if(x==0)
            {
                x=1;
            }
        }
        x=1;
      for(i=n-1;i>=0;i--)
        {
           x=x*nums[i];
            ans=max(ans,x);
            if(x==0)
            {
                x=1;
            }
        }
        return ans;
    }
};
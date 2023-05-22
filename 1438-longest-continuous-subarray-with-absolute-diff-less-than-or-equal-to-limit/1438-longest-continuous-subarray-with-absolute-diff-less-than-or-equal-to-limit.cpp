class Solution
{
    public:
        int longestSubarray(vector<int> &nums, int limit)
        {
            int l=0,r=0,ans=1,n=nums.size();
            map<int,int>m;
            while(l<n&&r<n)
            {
                m[nums[r]]++;
                auto it=m.begin();
                auto tt=m.rbegin();
                int st=it->first;
                int end=tt->first;
                if(abs(st-end)<=limit)
                {
                    ans=max(ans,abs(r-l+1));
                }
                else
                {
                    while(l<r)
                    {
                        auto it=m.begin();
                        auto tt=m.rbegin();
                        int st=it->first;
                        int end=tt->first;          
                          if(abs(st-end)<=limit)
                          {
                              ans=max(ans,abs(l-r+1));
                              break;
                          }
                        m[nums[l]]--;
                        if(m[nums[l]]==0)m.erase(nums[l]);
                        l++;
                        
                    }
                }
                r++;
            }
            return ans;
        }
};
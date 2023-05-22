#define ll long long int
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        ll sum=0,n=nums.size(),g=0,k=*max_element(nums.begin(),nums.end());
        nums.push_back(-1);
        for(int i=0;i<n;i++)
        {
            cout<<sum<<" ";
            if(i==0&&nums[i]>=nums[i+1])
            {
                sum+=(nums[i]);
                g++;
            }
            else if(i!=0&&nums[i]>=nums[i+1]&&nums[i]>=nums[i-1]&&g%2==0)
            {
                sum+=nums[i];
                g++;
            }
            else if(i!=0&&nums[i]<=nums[i+1]&&nums[i]<=nums[i-1]&&g%2==1)
            {
                sum-=nums[i];
                g++;
            }
        }
        return max(k,sum);
    }
};
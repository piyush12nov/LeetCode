class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int ans=INT_MIN,n=nums.size();
       sort(nums.begin(),nums.end());
        ans=max(ans,nums[n-3]*nums[n-2]*nums[n-1]);
        ans=max(ans,nums[0]*nums[1]*nums[2]);
        ans=max(ans,nums[0]*nums[1]*nums[n-1]);
       // ans=max(ans,nums[]*nums[n-2]*nums[n-1]);


     return ans;   
    }
};
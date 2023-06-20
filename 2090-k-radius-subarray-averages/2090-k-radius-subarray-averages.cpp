class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long int>pre(n+1,0);
        vector<int>ans;
        pre[0]=0;
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+nums[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            if(i-k-1<0||i+k>n)ans.push_back(-1);
            else
            {
                ans.push_back((pre[i+k]-pre[i-k-1])/(2*k+1));
            }
        }
        return ans;
    }
};
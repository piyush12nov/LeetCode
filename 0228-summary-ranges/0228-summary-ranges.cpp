class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>v;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            string temp;
            temp=to_string(x);
            while(i+1<n&&nums[i]+1==nums[i+1])i++;
            if(x==nums[i])v.push_back(temp);
            else
            {
                temp+="->";
                temp+=to_string(nums[i]);
                v.push_back(temp);
            }
        }
        return v;
    }
};
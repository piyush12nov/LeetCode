class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int no = int(nums.size() / 3) + 1;
        vector<int>ans;
        int e1=INT_MIN,e2=INT_MIN,c1=0,c2=0;
        for(auto x:nums)
        {
            if(c1==0&&e2!=x)
            {
                e1=x;
                c1=1;
                continue;
            }
            else if(c2==0&&e1!=x)
            {
                c2=1;
                e2=x;
                continue;
            }
            else if(e1==x){c1++;continue;}
            else if(e2==x)c2++;
            else
            {
                c1--;
                c2--;
            }
        }
        c1=0;c2=0;
        for(auto x:nums)
        {
            if(e1==x)c1++;
            if(e2==x)c2++;
        }
      
        if(c1>=no)ans.push_back(e1);
        if(c2>=no)ans.push_back(e2);
        return ans;
    }
};
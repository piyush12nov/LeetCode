class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char tar) {
        int l=0,r=v.size()-1,ans=INT_MAX;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(tar>=v[mid])
            {
                l=mid+1;
            }
            else if(tar<v[mid])
            {
                ans=min(mid,ans);
                r=mid-1;
            }
        }
        if(ans==INT_MAX)return v[0];
        return v[ans];
    }
};
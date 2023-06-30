class Solution {
public:
    int minimumCardPickup(vector<int>& a) {
        int ans=INT_MAX;
        int m[1000001];
        memset(m,-1,sizeof(m));
        for(int i=0;i<a.size();i++)
        {
            if(m[a[i]]!=-1)
            {
                ans=min(ans,abs(m[a[i]]-i)+1);
            }
            m[a[i]]=i;
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
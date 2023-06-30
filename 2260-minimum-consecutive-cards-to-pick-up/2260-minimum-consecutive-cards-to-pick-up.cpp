class Solution {
public:
    int minimumCardPickup(vector<int>& a) {
        int ans=INT_MAX;
        map<int,int>m;
        for(int i=0;i<a.size();i++)
        {
            if(m.find(a[i])!=m.end()&&m[a[i]]<=i)
            {
                ans=min(ans,abs(m[a[i]]-i)+1);
            }
            m[a[i]]=i;
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
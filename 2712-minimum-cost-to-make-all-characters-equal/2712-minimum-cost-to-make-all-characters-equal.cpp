class Solution {
public:
    long long minimumCost(string s) {
        long long ze=0,po=0,ans=0,n=s.size(),last=-1,x=0,i;
    
        for( i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                ans=ans+min(i,n-i);
            }
        }
        return ans;
    }
};
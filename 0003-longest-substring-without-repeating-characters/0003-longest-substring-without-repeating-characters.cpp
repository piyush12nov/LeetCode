class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,start=0;
        int m[105];
        memset(m,-1,sizeof(m));
        for(int i=0;i<s.size();i++)
        {
            int ss=s[i]-' ';
            if(m[ss]!=-1&&m[ss]>=start)
            {
                start=m[ss]+1;
            }
            ans=max(ans,abs(start-i)+1);
            m[ss]=i;
        }
        return ans;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,start=0;
        map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end()&&m[s[i]]>=start)
            {
                start=m[s[i]]+1;
            }
            ans=max(ans,abs(start-i)+1);
            m[s[i]]=i;
        }
        return ans;
    }
};
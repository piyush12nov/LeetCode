class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int i,j=0,n=s.size(),ans=INT_MIN,cn=0;
        map<char,int>m;
        for(i=0;i<n;i++)
        {
            m[s[i]]++;
            cn=max(cn,m[s[i]]);
            if(i+1-j-cn<=k)
            {
                ans=max(ans,i+1-j);
            }
            while(i+1-j-cn>k)
            {
                m[s[j]]--;
                j++;
                if(!m[s[j]])break;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numSplits(string s) {
        int n=s.size(),ans=0,i;
        vector<int>pre(n,1),suf(n,1);
        unordered_set<int>ss;
        for(int i=0;i<n;i++)
        {
            ss.insert(s[i]);
            pre[i]=ss.size();
        }
        ss.clear();
        for(i=n-1;i>=0;i--)
        {
            ss.insert(s[i]);
            suf[i]=ss.size();
        }
        for(i=1;i<n;i++)
        {
            if(pre[i-1]==suf[i])ans++;
        }
        return ans;
    }
};
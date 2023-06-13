#define ll long long int
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pat) {
        map<char,ll>m;
        ll ans=0;
        for(auto x:text)
        {
            if(pat[1]==x)
            {
                ans+=m[pat[0]];
            }
            m[x]++;
        }
        return ans+max(m[pat[0]],m[pat[1]]);
    }
};
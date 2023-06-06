#define ll long long
class Solution {
public:
    long long numberOfWays(string s) {
        ll s0=0,s1=0,s01=0,s10=0,s010=0,s101=0;
        for(auto c:s)
        {
            if(c=='0')
            {
                s0++;
                s10+=s1;
                s010+=s01;
            }
            if(c=='1')
            {
                s1++;
                s01+=s0;
                s101+=s10;
            }
        }
        return s101+s010;
    }
};
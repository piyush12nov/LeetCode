class Solution {
public:
    bool isHappy(int n) {
        map<long long int,int>m;
        while(true)
        {
            int cnt=0;
            int su=0;
            while(n)
            {
                su+=pow(n%10,2);
                n=n/10;
            }
            if(su==1)return 1;
            if(su<=3)return 0;
            n=su;
            if(m.find(su)!=m.end())return false;
            m[su]=1;
        }
        return true;
    }
};
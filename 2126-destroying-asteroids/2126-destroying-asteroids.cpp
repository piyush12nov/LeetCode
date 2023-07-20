class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long long int mm = mass;
        for(int i=0;i<a.size();i++)
        {
            if(mm>=a[i])
            {
                mm+=a[i];
            }
            else
            {
                return false;
            }
        }
        return 1;
    }
};
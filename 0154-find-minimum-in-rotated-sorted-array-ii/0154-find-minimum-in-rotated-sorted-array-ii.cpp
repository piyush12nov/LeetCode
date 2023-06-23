class Solution {
public:
    int findMin(vector<int>& a) {
        int ans=INT_MAX;
        for(auto x:a)
        {
            ans=min(ans,x);
        }
        return ans;
    }
};
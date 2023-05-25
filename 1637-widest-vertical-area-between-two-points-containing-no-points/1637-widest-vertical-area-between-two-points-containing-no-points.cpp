class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        int ans=0;
        for(int i=0;i<a.size()-1;i++)
        {
            ans=max(ans,a[i+1][0]-a[i][0]);
        }
        return ans;
    }
};
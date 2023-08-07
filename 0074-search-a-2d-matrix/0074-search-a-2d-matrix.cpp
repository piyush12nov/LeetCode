class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int i=0,n=v.size(),m=v[0].size(),j;
        int l=0,r=n*m-1;
        while(l<=r)
        {
             int mid=l+(r-l)/2;
            if(v[mid/m][mid%m]==target)return true;
            else if(v[mid/m][mid%m]<target)l=mid+1;
            else r=mid-1;
        }
        return false;
    }
};
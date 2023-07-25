class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size(),cnt,rev,i=0,ans=0;
        while(i<n)
        {
            cnt=1;
            if(i==n-1)break;
            if(i+1<n&&arr[i]==arr[i+1]){i++;continue;}
            while(i+1<n&&arr[i]<arr[i+1])
            {
                cnt++;
                i++;
            }
            rev=0;
            while(i+1<n&&arr[i]>arr[i+1])
            {
                rev++;
                i++;
            }
            if(rev>=1&&cnt>1)ans=max(ans,rev+cnt);
        }
        return ans;
    }
};
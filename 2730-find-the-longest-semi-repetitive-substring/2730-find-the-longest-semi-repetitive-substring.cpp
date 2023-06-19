class Solution {
public:
    int longestSemiRepetitiveSubstring(string a) {
        int i=0,j=0,n=a.size(),ans=1;
        for(int i=0;i<n;i++)
        {
            j=i;
            while(j+1<n&&a[j]!=a[j+1])j++;
            j++;
            while(j+1<n&&a[j]!=a[j+1])j++;
        
            ans=max(j-i+1,ans);
        }
        return min(ans,n);
    }
};
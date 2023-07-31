class Solution {
public:
    int dp[1005][1005];
    int lcs(string &s1,string &s2,int i,int j)
    {
        if(i==s1.size()||j==s2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        if(s1[i]==s2[j])
        {
            ans=s1[i]+lcs(s1,s2,i+1,j+1);
        }
        else
        {
            ans=max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
        }
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string word1, string word2) {     
        int m=word1.size(),n=word2.size(),sum=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++)sum+=word1[i];
        for(int i=0;i<n;i++)sum+=word2[i];
        int ans=lcs(word1,word2,0,0);
        return sum-2*ans;   
    }
};

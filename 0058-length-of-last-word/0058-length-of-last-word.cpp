class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            while(i<n&&s[i]==' ')i++;
            if(i<n&&s[i]!=' ')
            {
                ans=0;
                while(i<n&&s[i]!=' '){ans++;i++;}
            }
        }
        return ans;
    }
};
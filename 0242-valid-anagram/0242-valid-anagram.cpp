class Solution {
public:
    bool isAnagram(string s2, string s1) {
		int cnt[26]={};
        int n=s1.size(),i;
        if(n!=s2.size())return false;
        for(i=0;i<min(n,(int)s2.size());i++)
        {
            cnt[s2[i]-'a']++;
            cnt[s1[i]-'a']--;
        }
     
        for(i=0;i<n;i++)
        {
            if(cnt[s2[i]-'a']!=0)return false;
        }
        return true;
		}
};

    
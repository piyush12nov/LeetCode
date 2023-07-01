class Solution {
public:
    bool checkIfPangram(string s) {
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
  //      sort(s.begin(),s.end());
        cout<<s<<" "<<endl;
        for(int i=0;i<s.size();i++)
        {
            cnt[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(cnt[i]==0)return 0;
        }
        return 1;
    }
};
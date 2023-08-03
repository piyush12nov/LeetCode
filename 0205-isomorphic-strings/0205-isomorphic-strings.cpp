class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>vis(130,-1);
        for(int i=0;i<s.size();i++)
        {
            if(vis[s[i]-' ']!=-1&&vis[s[i]-' ']!=(t[i]-' '))return 0;
            vis[s[i]-' ']=t[i]-' '; 
        }
        vis.clear();
        vis.resize(130,-1);
        for(int i=0;i<s.size();i++)   
        {
            if(vis[t[i]-' ']!=-1&&vis[t[i]-' ']!=(s[i]-' '))return 0;
            vis[t[i]-' ']=s[i]-' ';
        }
        return true;
    }
};
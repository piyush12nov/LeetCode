class Solution {
public:
    int ff(vector<string>&a,int i,vector<int>cnt)
    {
        if(i==a.size())return 0;
        bool flag=true;
        
        int not_pick=ff(a,i+1,cnt);
            
        for(int j=0;j<a[i].size();j++)cnt[a[i][j]-'a']++;

        for(int j=0;j<26;j++)
        {
            if(cnt[j]>1)
            {
                flag=false;
                break;
            }
        }
        
        int pick=0;
        if(flag)
        {
            pick=a[i].size()+ff(a,i+1,cnt);
        }
    
        return max(not_pick,pick);
        
    }
    int maxLength(vector<string>& arr) {
        vector<int>cnt(26,0);
        return ff(arr,0,cnt);
    }
};
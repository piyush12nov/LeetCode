class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& v, int time) {
        int n=v.size(),cnt=1;
        vector<int>pre(n,1),suf(n,1),ans;
        for(int i=1;i<n;i++)
        {
            if(v[i]<=v[i-1])
            {
                cnt++;
            }
            else{cnt=1;}
            pre[i]=cnt;
        }
        cnt=1;
        for(int i=n-2;i>=1;i--)
        {
            if(v[i]<=v[i+1])
            {
                cnt++;
            }
            else{cnt=1;}
            suf[i]=cnt;
        }
        for(int i=0;i<n;i++)
        {
       //     cout<<pre[i]<<" "<<suf[i]<<endl;
            if(pre[i]>=time+1&&suf[i]>=time+1)ans.push_back(i);
        }
        cout<<endl;
        return ans;
    }
};
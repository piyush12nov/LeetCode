class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& v) {
        int n=v.size();
        vector<int>ans(n,1);
        ans[n-1]=0;
        stack<int>s;
        s.push(v[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            int x=v[i];
            int y=1;
            while(s.size()>=1&&x>s.top())
            {
                y++;
                s.pop();
            }
            
            if(s.empty())
            ans[i]=y-1;
            else ans[i]=y;
            s.push(x);
        }
        return ans;
    }
};
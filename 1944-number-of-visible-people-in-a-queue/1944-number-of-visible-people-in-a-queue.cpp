class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& v) {
        int n=v.size();
        vector<int>ans(n,0);
        stack<int>s;
      //  s.push(v[n-1]);
        for(int i=n-1;i>=0;i--)
        {
            int x=v[i];
            cout<<i<<" = I "<<" ";
            while(s.size()>=1&&x>s.top())
            {
                ans[i]++;
                s.pop();
            }   
            if(!s.empty())
            ans[i]++;
         
                s.push(x);
            
        }
        ans[n-1]=0;

        return ans;
    }
};
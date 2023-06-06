class Solution {
public:
//     int dp[30005];
//     int ff(int i,int cnt,string s)
//     {
//         if(i>=s.size())return 0;
//         if(dp[i]!=-1)return dp[i];
//         int a=0,b=0,c=0;
//         if(s[i]=='(')
//         {
//             a=ff(i+1,cnt+1,s);
//         }
//         if(cnt>0&&s[i]==')')
//         {
//             b=1+ff(i+1,cnt-1,s);
//         }
      
//         return dp[i]=max({a,b});
//     }
    int longestValidParentheses(string s) {
        vector<pair<int,int>>v;
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++)
        {
            char ch='1';
            int ind=-1;
            if(!st.empty()){
             ch=st.top().first;
             ind=st.top().second;}
            int kk=i;
            int flag=0;
            if(!st.empty()&&s[i]==')'&&ch=='(')
            {
                st.pop();
                flag=1;
            }
            if(flag)
            {
                v.push_back({ind,kk});
            }  
            if(flag==0&&s[i]=='(')
            {
                st.push(make_pair('(',i ));
            }
    }
        sort(v.begin(),v.end());
        for(auto x:v)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
        int ans=0,nn=v.size();
        for(int i=0;i<nn;i++)
        {
            int a=v[i].first;
            int b=v[i].second;
            int flag=0;
           cout<<a<<"  bhar "<<b<<endl;
            while( i+1<nn&& v[i+1].first<=b+1)
            {

                a=min(v[i+1].first,a);
                b=max(v[i+1].second,b);
           cout<<a<<" PPP  "<<b<<endl;

                i++;
                flag=1;
            }
        //    if(flag==1)i--;
            
                cout<<a<<" reeee "<<b<<endl;
            ans=max(ans,b-a+1);
        }

        return ans;
    }
};
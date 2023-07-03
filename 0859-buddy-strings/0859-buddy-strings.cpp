class Solution
{
    public:
        bool buddyStrings(string a, string b)
        {
            if(a.size()!=b.size())return 0;
            string s;
            map<string,int>m,mm;
            bool flag=false,fl=false;
            int cnt=0;
            for (int i = 0; i < a.size(); i++)
            {
                
                int x=a[i]-'a',y=b[i]-'a';
                cout<<x<<" "<<y<<endl;
                if (a[i] != b[i])
                {
                       s='a'+x;
                s+='a'+y;
                m[s]++;
                    cnt++;
                }
                else{
                       s='a'+x;
                s+='a'+y;
                mm[s]++;
                }
             
              //..  cout<<s<<" ";
            }
            if(cnt%2==1)return 0;
            for(auto [x,y]:m)
            {
                string s=x;
              //  cout<<x<<" ";
                reverse(s.begin(),s.end());
                cout<<s<<" "<<x<<endl;
                if(m.find(s)!=m.end())fl=true;
            }
            for(auto [x,y]:mm)
            {
                if(x[0]==x[1]&&y>=2)flag=true;
}
            if(cnt==0&&flag)return 1;
            if(cnt==2&&fl)return 1;
            return 0;
        }
};
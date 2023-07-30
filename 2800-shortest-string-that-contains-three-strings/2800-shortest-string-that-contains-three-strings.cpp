class Solution {
public:
    
    vector<vector<string>>v;
    bool static cmp(string &a,string &b)
    {
        if(a.size()!=b.size())return a.size()<b.size();
        return a<b;
    }
    void ff(int i,vector<string>&ss)
    {
        int n=ss.size();
        if(i==n-1)
        {
            v.push_back(ss);
        }
        for(int j=i;j<n;j++)
        {
            swap(ss[j],ss[i]);
            ff(i+1,ss);
            swap(ss[j],ss[i]); 
        }
        return ;
    }
    string minimumString(string a, string b, string c) {
        vector<string>temp;
        int max_size=0;
        temp.push_back(a);
        max_size=max(max_size,(int)a.size());
        temp.push_back(b);
        max_size=max(max_size,(int)b.size());
        temp.push_back(c);
        max_size=max(max_size,(int)c.size());
        ff(0,temp);
        vector<string>ans;
  for (int i = 0; i < 6; i++)
  {
      string res=v[i][0];
      //for(int k=0;k<3;k++)cout<<v[i][k]<<" ";
    //  cout<<endl;
  	for (int k = 0; k < 2; k++)
  	{
  		string temp, st;

        int uy=0;
  		for (int j = 0; j < v[i][k + 1].size(); j++)
            st += v[i][k + 1][j];
        if(res.find(st)!=string::npos)continue;
  		for (int j = res.size()-1; j>=0; j--)
  		{
  			temp +=res[j];
  		reverse(temp.begin(), temp.end());

  			auto s = st.find(temp);
            
  		reverse(temp.begin(), temp.end());

  			if (s == string::npos||s!=0)continue;
            
          //  cout<<temp<<endl;
            uy=temp.size();
  		}
        
        for(int p=uy;p<v[i][k+1].size();p++)
            res=res+v[i][k+1][p];
       // cout<<res<<" ";
  	}
     // cout<<endl;
     ans.push_back(res);

  }
        sort(ans.begin(),ans.end(),cmp);
        
  for(auto x:ans)cout<<x<<" ";cout<<endl;
        return ans[0];
    }
};
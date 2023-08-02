//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string x, string y) {
        int n=x.size()-1,m=y.size()-1,rem=0,i=0,j=0;
        reverse(x.begin(),x.end());
        reverse(y.begin(),y.end());
        string ans="";
        while(i<=n&&j<=m)
        {
            int n1=x[i]-'0';
            int n2=y[j]-'0';
            int n3=n1+n2+rem;

            ans=to_string(n3%10)+ans;
            rem = n3/10;
            i++;j++;   
        }
        while(i<=n)
        {
            int n1=x[i]-'0';
            int n3=n1+rem;

            ans=to_string(n3%10)+ans;
            rem=n3/10;
            i++;
        }
        i=j;

        while(i<=m)
        {
            int n1 = y[i]-'0';
            int n3 = n1+rem;           

            ans=to_string(n3%10)+ans;
            rem=n3/10;
            i++;   
        }
        if(rem!=0)
        {
            ans=to_string(rem)+ans;
        }
        reverse(ans.begin(),ans.end());
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(ans[i]!='0')break;
            ans.pop_back();
        }
            
        reverse(ans.begin(),ans.end());
        if(ans.size()==0)return "0";
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        int i,s=0,ans=0,ss=a.size();
        unordered_map<int,int>m;
        for(i=0;i<n;i++)
        {
            s+=a[i];
            if(s==0)ans=max(ans,i+1);
            if(m.count(s)>0)
            {
                ans=max(ans,i-m[s]+1);
            }
            else
            {
                m[s]=i+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
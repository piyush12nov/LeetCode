//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& a, int n) {
        for(int i=0;i<n-1;i++)
        {
            int x=abs(a[i])-1;
            if(x>n-2)continue;
            a[x]=-1*a[x];
        }
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>0)return i+1;
        }
        return n;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends
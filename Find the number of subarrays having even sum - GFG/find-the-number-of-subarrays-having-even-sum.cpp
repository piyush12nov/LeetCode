//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long countEvenSum(int arr[], int n) {
        long long s = 0,ans = 0;
        map<int,int>m;
        m[0]=1;
        for(int i=0;i<n;i++)
        {
            s+=arr[i];
            ans+=m[s%2];
            m[s%2]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countEvenSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}


// } Driver Code Ends
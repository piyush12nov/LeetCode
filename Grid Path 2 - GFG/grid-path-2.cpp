//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int mod=1e9+7;
    int dp[105][105];
    int lund(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        if(i<0||j<0||i>=n||j>=m||grid[i][j]==1)return 0;
        if(i==n-1&&j==m-1&&grid[i][j]==0)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=lund(grid,i+1,j,n,m)%mod;
        int b=lund(grid,i,j+1,n,m)%mod;
        return dp[i][j]=(a+b)%mod;
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return lund(grid,0,0,n,m);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends
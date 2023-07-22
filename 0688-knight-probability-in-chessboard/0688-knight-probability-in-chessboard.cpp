class Solution {
public:
    
    vector<vector<vector<double>>>dp;
    double ff(int i,int j,int k,int n)
    {
        if(i<0||j<0||i>=n||j>=n)return 0;
        if(dp[i][j][k]!=-1.0)return dp[i][j][k];        
        if(k==0)return 1.0;

        double cnt = ff(i+2,j+1,k-1,n)+ff(i+2,j-1,k-1,n)+ff(i-2,j+1,k-1,n)+ff(i-2,j-1,k-1,n)+
            ff(i+1,j+2,k-1,n)+ff(i-1,j+2,k-1,n)+ff(i+1,j-2,k-1,n)+ff(i-1,j-2,k-1,n);        cout<<cnt/8.0<<endl;

        return dp[i][j][k]=cnt/8.0;
        
    }
    double knightProbability(int n, int k, int row, int column) {
        dp.resize(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1.0)));
        return ff(row,column,k,n);
    }
};
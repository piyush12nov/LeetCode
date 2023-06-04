#define ll long long int
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        ll sum=0;
        ll rr=n,rc=n;
        vector<int>row(n,-1),col(n,-1);
        reverse(queries.begin(),queries.end());
        for(auto x:queries)
        {
            ll type=x[0],ind=x[1],val=x[2];
            if(type==0)
            {
               
                if(row[ind]==-1)
                {
                    sum += val*rc;
                    rr--;
                    row[ind]=122;
                }
            }
            else if(type==1)
            {
                if(col[ind]==-1)
                {
                    sum += val*rr;
                    rc--;
                    col[ind]=122;
                }
            }
        }
        return sum;
    }
};
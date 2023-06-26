
#define ll long long int
class Solution
{
    public:
        long long totalCost(vector<int> &a, int can, int k)
        {
            ll n = a.size();
            ll l = 0, r = n - 1, ans = 0, flag = 0;
            vector<int> vis(n, 0);
            priority_queue<int, vector < int>, greater < int>> p1, p2;
            while (l < k && !vis[l])
            {
                p1.push(a[l]);
                vis[l] = 1;
                l++;        
                flag=1;
            }
            if(flag)
            {
                flag=0;
                l--;
            }
            while (r >= n - k && !vis[r])
            {
                p2.push(a[r]);
                vis[r] = 1;
                r--;
                flag=1;
            }
            if(flag){
                
            r++;}
            while (can)
            {
                ll x=INT_MAX,y=INT_MAX;
              //  cout<<p1.size()<<" size "<<p2.size()<<endl;
                if(p1.size()>=1)
                 x = p1.top();
                if(p2.size()>=1)
                 y = p2.top();
              //  cout<<x<<"  "<<y<<endl;
                if (x <= y)
                {
             //   cout<<x<<"  reladle  "<<y<<endl;

                    can--;
                    ans += x;
                    p1.pop();
                    l++;
                    if (l<n&&!vis[l] )
                    {
                        p1.push(a[l]);
                        vis[l] = 1;
                    }
                }
                else
                {
               //     cout<<x<<"  43443reladle  "<<y<<endl;
                    can--;
                    ans += y;
                    p2.pop();
                    r--;
                    if (r >= 0 && !vis[r])
                    {
                        p2.push(a[r]);
                        vis[r] = 1;
                    }
                }
            }
         //   cout<<endl;
            return ans;
        }
};
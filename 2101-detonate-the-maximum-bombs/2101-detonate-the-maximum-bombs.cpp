#define ll long long int
class Solution {
public:
    void dfs(int i,vector<int>&vis,vector<int>adj[])
    {
        vis[i]=1;
        for(auto x:adj[i])
        {
            if(vis[x]==0)dfs(x,vis,adj);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs){
        int n=bombs.size(),i,j,ans=1;
        vector<int>adj[n];
        vector<int>vis(n,0);
       for(int i=0; i<n; i++){
        ll x1 = bombs[i][0];
        ll y1 = bombs[i][1];
        ll r1 = bombs[i][2];
        
        for(int j=0; j<n; j++){
            if(i != j){
                ll x2 = bombs[j][0];
                ll y2 = bombs[j][1];        
                ll xx = abs(x2-x1);
                ll yy = abs(y2-y1);           
                if(xx*xx + yy*yy <= r1*r1){
                    adj[i].push_back(j);      
                }
            }      
        }    
    }
    
            for(i=0;i<n;i++)
            {
                dfs(i,vis,adj);
                int cnt=0;
                for(j=0;j<n;j++)
                {
                    if(vis[j]==1)cnt++;
                } 
                fill(vis.begin(),vis.end(),0);
                ans=max(ans,cnt);
                
                
            }
        
        return ans;
    }
};
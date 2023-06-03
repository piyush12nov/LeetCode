class Solution {
public:
    // void dfs(int node,vector<pair<int,int>>adj[],vector<int>&vis,int s)
    // {
    //     vis[node]=1;
    //     ans=max(ans,s);
    //     cout<<node<<" "<<s<<endl;
    //     for(auto x:adj[node])
    //     {
    //         if(vis[x.first]==0)
    //         {
    //             dfs(x.first,adj,vis,s+x.second);
    //         }
    //     }
    // }
    int numOfMinutes(int n, int headID, vector<int>& man, vector<int>& intm) {
        int i,j,ans=0;
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(i=0;i<n;i++)
        {
            if(man[i]==-1)continue;
            adj[man[i]].push_back(i);
        }   
        queue<pair<int,int>>q;
        q.push({headID,0});
        while(!q.empty())
        {
            auto ne=q.front();
            int node=ne.first;
            int ss=ne.second;
            ans=max(ss,ans);
            q.pop();
            int cost=0;
            for(auto x:adj[node])
            {
              cost=intm[man[x]];
              q.push({x,cost+ss});     
            }
        }
        return ans;
    }
};
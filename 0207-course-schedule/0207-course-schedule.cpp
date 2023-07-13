class Solution {
public:
    int cnt=0;
     bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 2; 
        for(auto adjacentNode: adj[node]) {
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, node, vis, adj) == true) 
                    return true; 
            }
            if(vis[adjacentNode]==2) return true; 
        }
         vis[node]=1;
        return false; 
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
     vector<int>adj[n];
        int i;
        int vis[n];
        memset(vis,0,sizeof vis);
        for(auto x:pre)
        {
            adj[x[1]].push_back(x[0]);
        }
        for(i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
               if(dfs(i,-1,vis,adj))return false;
            }
        }
        return true;
    }
};
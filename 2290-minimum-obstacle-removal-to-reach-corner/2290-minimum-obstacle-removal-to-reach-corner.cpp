class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
     
        q.push({0,{0,0}});
        
        while(!q.empty())
        {
            auto v=q.top();
            q.pop();
            int c=v.first,i=v.second.first,j=v.second.second;
            if(vis[i][j]==1)continue;
            vis[i][j]=1;
            if(i==n-1&&j==m-1)return c;
            if(i+1<n&&vis[i+1][j]==0)
            {
                q.push({c+grid[i+1][j],{i+1,j}});             
            }
            if(j+1<m&&vis[i][j+1]==0)
            {
                q.push({c+grid[i][j+1],{i,j+1}});
            }
            if(i-1>=0&&vis[i-1][j]==0)
            {
                q.push({c+grid[i-1][j],{i-1,j}});
            }
            if(j-1>=0&&vis[i][j-1]==0)
            {
                q.push({c+grid[i][j-1],{i,j-1}});
            }
        }
        return 0;
    }
};
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int re=INT_MAX;
        for(auto it:points)
        {
            if(it[0]==x||it[1]==y)
            {
                re=min(re,abs(x-it[0])+abs(y-it[1]));
            }
            
        }
        int i=0;
        for(auto it:points)
        {
            if(it[0]==x||it[1]==y)
            {
                if(re==abs(x-it[0])+abs(y-it[1]))return i;
            }
            i++;
        }
        return -1;
    }
};
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coo) {
        for(int i=0;i<coo.size()-2;i++)
        {
            if(coo[i][0]==coo[i+1][0]&&coo[i+1][0]==coo[i+2][0])continue;
            float a=(((float)coo[i][1]-coo[i+1][1])/((float)coo[i][0]-coo[i+1][0]));
            float b=(((float)coo[i+1][1]-coo[i+2][1])/((float)coo[i+1][0]-coo[i+2][0]));
            cout<<a<<" "<<b<<endl;
            if(a!=b)return 0;
        }
        return 1;
    }
};
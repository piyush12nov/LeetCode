class UndergroundSystem {
public:
    map<int,pair<string,int>>m;
    map<pair<string,string>,int>mp,mm;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stt, int t) {
        m[id]={stt,t};
    }
    
    void checkOut(int id, string end, int t) {
        string st=m[id].first;
        mm[{st,end}]++;
        mp[{st,end}]+=t-m[id].second;
    }
    
    double getAverageTime(string st, string end) {
        return ((double)mp[{st,end}]/((double) mm[{st,end}]));
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
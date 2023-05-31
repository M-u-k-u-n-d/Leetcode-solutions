class UndergroundSystem {
    map<int,pair<string,int>>mmp;
    map<string,vector<int>> mpp;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mmp[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string s = mmp[id].first;
        s += "@" + stationName;
        int num = abs(mmp[id].second - t);
        mpp[s].push_back(num);
    }
    
    double getAverageTime(string startStation, string endStation) {
       string s = startStation + "@"+ endStation;
        int sum = 0;
        for(int i=0; i<mpp[s].size(); i++){
            sum += mpp[s][i];
        }
        
        double ans = sum*1.0/mpp[s].size();
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
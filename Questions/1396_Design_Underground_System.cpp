#define sc second
#define fr first
class UndergroundSystem {
public:
    map<int,pair<string,string>>mp;
    map<int,pair<int,int>>mp1;
    map<pair<string,string>,vector<pair<int,int>>>mp2;
    UndergroundSystem() {
    
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id]={stationName,""};
        mp1[id]={t,0};
    }
    
    void checkOut(int id, string stationName, int t) {
        mp[id].sc=stationName;
        mp1[id].sc=t;
        mp2[{mp[id].first,mp[id].second}].push_back(mp1[id]);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double s=0;
        if(mp2.count({startStation,endStation})==1)
        {
            auto n=mp2[{startStation,endStation}];
            for(auto i:n)
            {
                s+=(i.sc-i.fr);
            }
            s/=n.size()*1.0;
            return s;
        }
        return s;
    }
};

//Space Efficient
 
#define sc second
#define fr first
class UndergroundSystem {
public:
    map<int,string>mp;
    map<int,int>mp1;
    map<pair<string,string>,vector<int>>mp2;
    
    UndergroundSystem() {
    
        
    }
    void checkIn(int id, string stationName, int t) {
        mp[id]=stationName;
        mp1[id]=t;
    }
    
    void checkOut(int id, string stationName, int t) {
        mp2[{mp[id],stationName}].push_back(t-mp1[id]);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double s=0;
        if(mp2.count({startStation,endStation})==1)
        {
            auto n=mp2[{startStation,endStation}];
            for(auto i:n)
            {
                s+=(i);
            }
            s/=n.size()*1.0;
            return s;
        }
        return s;
    }
};


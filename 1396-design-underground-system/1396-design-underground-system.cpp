class UndergroundSystem
{
    public:
    
    // <start-station, end-station, <sum, totalTrips>>
    unordered_map<string, unordered_map<string,pair<int, int>>> tripStatistics; 
    
    // <id, <start-station, start-time>>
    unordered_map<int, pair<string, int>> activeTrips;   
        
    UndergroundSystem() { }
    
    void checkIn(int id, string startStation, int t)
    {
        activeTrips[id].first = startStation;
        activeTrips[id].second = t;
    }
    
    void checkOut(int id, string endStation, int t)
    {
        int duration = t - activeTrips[id].second;
        tripStatistics[activeTrips[id].first][endStation].first += duration;
        tripStatistics[activeTrips[id].first][endStation].second++;
        
        // erase when trip is ended.
        activeTrips.erase(activeTrips.find(id));
    }
    
    double getAverageTime(string startStation, string endStation)
    {
        int totalDuration = tripStatistics[startStation][endStation].first;
        int totalTrips = tripStatistics[startStation][endStation].second;
        return totalDuration/(double)totalTrips;
    }
};

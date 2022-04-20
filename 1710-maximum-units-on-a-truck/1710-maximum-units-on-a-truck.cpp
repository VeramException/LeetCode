class Solution
{
    public:    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), [] (vector<int> a, vector<int> b) { return a[1] > b[1]; });
        
        int units = 0;
        for (vector<int> box: boxTypes)
        {
            if (truckSize <= 0)
                break;
            
            units = units + min(truckSize, box[0])*box[1];            
            truckSize = truckSize - box[0];
        }
        return units;
    }
};
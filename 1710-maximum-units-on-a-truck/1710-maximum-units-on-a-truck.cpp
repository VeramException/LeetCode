class Solution
{
    public:
    static bool customCompare(vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), customCompare);
        
        int units = 0, boxes = 0;
        for (vector<int> box: boxTypes)
        {
            if (boxes + box[0] > truckSize)
            {
                units = units + (truckSize - boxes)*box[1];
                break;
            }
            else
            {
                units = units + box[0]*box[1];
                boxes = boxes + box[0];
            }
            
        }
        return units;
    }
};
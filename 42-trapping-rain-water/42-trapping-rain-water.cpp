class Solution
{
    public:
    int trap(vector<int>& height)
    {
        int N = height.size();
        
        // Step-1: Capture what is the max height on the left side at each 'i'
        vector<int> lMaxHeight (N, 0);        
        for (int i=1; i<N; i++)
            lMaxHeight[i] = max (lMaxHeight[i-1], height[i-1]);
        
        // Step-2: Capture what is the max height on the right side at each 'i'
        vector<int> rMaxHeight (N, 0);
        for (int i=N-2; i>=0; i--)
            rMaxHeight[i] = max (rMaxHeight[i+1], height[i+1]);
        
        // Step-3: Height of water at 'i' is nothing but the minimum height of both sides
        int totalWater = 0;
        for (int i=0; i<N; i++)
        {
            int waterLevel = min(lMaxHeight[i], rMaxHeight[i]);
            
            if (waterLevel > height[i])
                totalWater += (waterLevel - height[i]);
        }
        return totalWater;
    }
};
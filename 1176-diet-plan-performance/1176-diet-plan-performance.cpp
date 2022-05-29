class Solution
{
    public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper)
    {
        int points = 0, currStreak = k, burntCals = 0;
        
        for (int i=0; i<calories.size(); i++)
        {            
            burntCals += calories[i];
            currStreak--;
            
            if (currStreak == 0)
            {
                if (burntCals < lower) points--;
                if (burntCals > upper) points++;
                
                currStreak++;
                burntCals = burntCals - calories[i-k+1];
            }
        }
        
        return points;
    }
};
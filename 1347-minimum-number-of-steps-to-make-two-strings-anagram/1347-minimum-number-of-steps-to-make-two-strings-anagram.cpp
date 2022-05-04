class Solution
{
    public:    
    #define NO_OF_CHARS 128
    
    int minSteps(string s1, string s2)
    {
        int totalSteps = 0;
        int count[NO_OF_CHARS] = {0};
        
        for (int i = 0; i < s1.size(); i++)
            count[s1[i]]++;
        
        for (int i = 0; i < s2.size(); i++)
            count[s2[i]]--;
                
        for (int i = 0; i < NO_OF_CHARS; i++)
            if (count[i] != 0)
                totalSteps = totalSteps + abs(count[i]);
        
        return totalSteps/2;
    }
};
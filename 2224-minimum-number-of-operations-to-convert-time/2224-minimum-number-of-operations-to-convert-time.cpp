class Solution
{
    public:
    int convertTime(string current, string correct)
    {
        int h1 = stoi(current.substr(0, 2));
        int m1 = stoi(current.substr(3, 2));
        
        int h2 = stoi(correct.substr(0, 2));
        int m2 = stoi(correct.substr(3, 2));
        
        int mm1 = h1*60+m1;
        int mm2 = h2*60+m2;
        
        int count = 0;
        
        while (mm2-mm1 >= 60)
        {
            mm1 += 60;
            count++;
        }        
        while (mm2-mm1 >= 15)
        {
            mm1 += 15;
            count++;
        }
        while (mm2-mm1 >= 5)
        {
            mm1 += 5;
            count++;
        }
        while (mm2-mm1 >= 1)
        {
            mm1 += 1;
            count++;
        }
        
        return count;
    }
};
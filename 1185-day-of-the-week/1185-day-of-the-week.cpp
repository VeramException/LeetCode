class Solution
{
    public:
    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};    
    vector<string> daysOfWeek = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    string dayOfTheWeek(int day, int month, int year)
    {
        int totalDays = daysFromZero(day, month, year);
        return daysOfWeek[(totalDays-1)%7];
    }
    
    int daysFromZero(int d, int m, int y)
    {       
        for (int i=0; i<m-1; i++)
            d += daysInMonth[i];
        
        if (m>2 && isLeapYear(y))
            d++;
        
        d += 365*y + countLeapYears(y-1);
        
        return d;
    }
    
    bool isLeapYear(int y)
    {
        return (y % 4 == 0) && (y % 100 != 0 || y % 400 == 0);
    }
    
    int countLeapYears(int y)
    {
        return floor(y/4) - floor(y/100) + floor(y/400);
    }
};
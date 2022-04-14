class Solution
{
    public:
    vector<int> daysOfMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int daysBetweenDates(string date1, string date2)
    {
        // Count days from 0-Jan-0000 to date1
        int days1 = daysFromZero(date1);
        
        // Count days from 0-Jan-0000 to date2
        int days2 = daysFromZero(date2);
        
        return abs(days1-days2);
    }
    
    int daysFromZero(string date)
    {
        int y = stoi(date.substr(0,4));
        int m = stoi(date.substr(5,2));
        int d = stoi(date.substr(8,2));
        
        int days = 365*y + d;
        
        for (int i=0; i<m-1; i++)
            days += daysOfMonth[i];
        
        // Add current month days, and also add '1' extra if we are already past Feb and if this is a Leap year
        if (m>2 && isLeapYear(y))
            days++;
        
        // Important: We need to add count # of Leap years from 0 to y-1
        days += countLeapYears(y-1);
        
        return days;
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
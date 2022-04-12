class Solution
{
    public:
    vector<int> daysOfMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};    
    vector<string> daysOfWeek = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
    
    string dayOfTheWeek(int day, int month, int year)
    {
        int totalDays = daysFrom1971(day, month, year);
        return daysOfWeek[(totalDays-1)%7];
    }
    
    int daysFrom1971(int d, int m, int y)
    {        
        for (int iy=1971; iy<y; iy++)
            d += isLeapYear(iy)? 366: 365;

        for (int im=0; im<m-1; im++)
            d += daysOfMonth[im];
        
        if (m > 2 && isLeapYear(y))
            d++;
        
        return d;
    }
    
    bool isLeapYear(int y)
    {
        return (y % 4 == 0) && (y % 100 != 0 || y % 400 == 0);
    }
};
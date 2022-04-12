class Solution
{
    public:
    vector<int> daysOfMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int daysBetweenDates(string date1, string date2)
    {
        return abs(daysFrom1971(date1)-daysFrom1971(date2));
    }
    
    int daysFrom1971(string date)
    {
        int y = stoi(date.substr(0,4));
        int m = stoi(date.substr(5,2));
        int d = stoi(date.substr(8,2));
        
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
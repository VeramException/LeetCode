class Solution
{
    public:
    vector<int> daysOfMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int daysBetweenDates(string date1, string date2)
    {
        if (date1 < date2)
        {
            int y1 = stoi(date1.substr(0,4));
            return daysFromLastYear(date2, y1-1) - daysFromLastYear(date1, y1-1);            
        }
        else
        {
            int y2 = stoi(date2.substr(0,4));
            return daysFromLastYear(date1, y2-1) - daysFromLastYear(date2, y2-1);
        }
    }
    
    int daysFromLastYear(string date, int fromYear)
    {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int y = stoi(date.substr(0,4));
        int m = stoi(date.substr(5,2));
        int d = stoi(date.substr(8,2));
        
        for (int iy=fromYear; iy<y; iy++)
            d += isLeapYear(iy)? 366: 365;
        
        for (int im=0; im<m-1; im++)
            d += daysInMonth[im];
        
        if (m>2 && isLeapYear(y))
            d++;
        
        return d;
    }
    
    bool isLeapYear(int y)
    {
        return (y % 4 == 0) && (y % 100 != 0 || y % 400 == 0);
    }
};
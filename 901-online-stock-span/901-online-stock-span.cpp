class StockSpanner
{
    public:
    stack<pair<int, int>> s;
    
    StockSpanner()
    {
        
    }
    
    int next(int price)
    {
        int maxDays = 1;
        while (!s.empty() && s.top().first <= price)
        {
            maxDays += s.top().second;
            s.pop();
        }
        s.push({price, maxDays});
        
        return maxDays;
    }
};
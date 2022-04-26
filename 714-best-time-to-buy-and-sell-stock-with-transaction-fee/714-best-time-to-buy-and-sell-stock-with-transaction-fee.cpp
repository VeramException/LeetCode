class Solution
{
    public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int buyToday  = -prices[0];
        int sellToday = 0;
        
        for (int i=1; i<prices.size(); i++)
        {
            int prevDayBuy  = buyToday;
            int prevDaySell = sellToday;;
            
            buyToday  = max (prevDayBuy, prevDaySell-prices[i]);
            sellToday = max (prevDaySell, prevDayBuy+prices[i]-fee);
        }
        
        return sellToday;
    }
};
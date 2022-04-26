class Solution 
{
    // Same as https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
    // with fee = 0.
    
    public:
    int maxProfit(vector<int>& prices) 
    {
        int buyToday  = -prices[0];
        int sellToday = 0;
        
        for (int i=1; i<prices.size(); i++)
        {
            int prevDayBuy  = buyToday;
            int prevDaySell = sellToday;
            
            buyToday  = max (prevDayBuy, prevDaySell-prices[i]);
            sellToday = max (prevDaySell, prevDayBuy+prices[i]-0);
        }
        
        return sellToday;
    }
};
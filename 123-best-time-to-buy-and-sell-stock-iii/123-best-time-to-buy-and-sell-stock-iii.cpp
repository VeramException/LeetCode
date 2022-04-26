class Solution
{
    public:
    int maxProfit(vector<int>& prices)
    {
        int buy_1  = INT_MAX;
        int sell_1 = 0;
        int buy_2  = INT_MAX;
        int sell_2 = 0;
        
        for (int i=0; i<prices.size(); i++)
        {
            int prev_buy_1  = buy_1;
            int prev_sell_1 = sell_1;
            int prev_buy_2  = buy_2;
            int prev_sell_2 = sell_2;
            
            buy_1  = min (prev_buy_1,  prices[i]);
            sell_1 = max (prev_sell_1, prices[i]-prev_buy_1);
            buy_2  = min (prev_buy_2,  prices[i]-prev_sell_1);
            sell_2 = max (prev_sell_2, prices[i]-prev_buy_2);
        }
        
        return sell_2;
    }
};
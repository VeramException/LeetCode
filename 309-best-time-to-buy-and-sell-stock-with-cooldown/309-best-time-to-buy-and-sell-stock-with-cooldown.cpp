class Solution
{
    public:
    int maxProfit(vector<int>& prices)
    {
        // (1) - have 1 , do nothing    -----> previous step = (1) or (4)
        // (2) - have 1 , sell          -----> previous step = (1) or (4)
        // (3) - have 0 , do nothing    -----> previous step = (2) or (3)
        // (4) - have 0 , buy           -----> previous step = (3) 
        
        int have1_doNothing = -prices[0];
        int have1_sell      = 0;
        int have0_doNothing = 0;
        int have0_buy       = -prices[0];
        
        for (int i=1; i<prices.size(); i++)
        {
            int op1 = have1_doNothing;
            int op2 = have1_sell;
            int op3 = have0_doNothing;
            int op4 = have0_buy;
            
            have1_doNothing = max (op1, op4);
            have1_sell      = max (op1, op4) + prices[i];
            have0_doNothing = max (op2, op3);
            have0_buy       = op3 - prices[i];
        }
        
        return max ({have1_doNothing, have1_sell, have0_doNothing, have0_buy});
    }
};
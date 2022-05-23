class Solution
{
    public:
    int change(int amount, vector<int>& coins)
    {
        if (amount == 0)
            return 1;
        if (coins.size() == 0)
            return 0;
        
        vector<int> DP(amount+1, 0);
        
        DP[0]=1;
        for (int coin: coins)
        {
            for (int a=1; a<=amount; a++)
            {
                if (coin <= a)
                    DP[a] = DP[a] + DP[a-coin];
            }
        }
        
        return DP[amount];
    }
};


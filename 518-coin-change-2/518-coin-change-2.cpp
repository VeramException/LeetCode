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
        for (int r=0; r<coins.size(); r++)
        {
            for (int c=1; c<=amount; c++)
            {
                if (coins[r] <= c)
                    DP[c] = DP[c] + DP[c-coins[r]];
            }
        }
        
        return DP[amount];
    }
};


class Solution
{
    public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum)
    {
        // Base case
        if (accumulate(colsum.begin(), colsum.end(), 0) != upper+lower)
            return {};
       
        int big   = max(upper, lower);
        int small = min(upper, lower);

        int N = colsum.size();
        vector<int> bigger(N, 0);
        vector<int> smaller(N, 0);
        
        // First go through bigger one and fill all the colsum positions with value '2'
        for (int i=0; i<N; i++)
        {
            if (colsum[i] == 2)
            {
                bigger[i] = 1;
                colsum[i]--;
                big--;
            }
        }
        
        for (int i=0; i<N; i++)
        {
            if (big > 0 && colsum[i] == 1 && bigger[i] == 0)
            {
                bigger[i] = 1;
                colsum[i]--;
                big--;
            }
        }
        
        if (big != 0)
            return {};
        
        for (int i=0; i<N; i++)
        {
            if (small > 0 && colsum[i] == 1 && smaller[i] == 0)
            {
                smaller[i] = 1;
                colsum[i]--;
                small--;
            }
        }
        
        if (small != 0)
            return {};
        
        if (upper > lower)
            return {bigger, smaller};
        else
            return {smaller, bigger};
    }
};
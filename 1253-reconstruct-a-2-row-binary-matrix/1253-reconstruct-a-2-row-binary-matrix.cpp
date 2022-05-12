class Solution
{
    public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum)
    {
        int N = colsum.size();
        vector<int> upperRow(N, 0);
        vector<int> lowerRow(N, 0);
        
        for (int i=0; i<colsum.size(); i++)
        {
            if (colsum[i] == 2)
            {
                upperRow[i] = 1;
                lowerRow[i] = 1;
                upper--;
                lower--;
            }
            else if (colsum[i] == 1)
            {
                if (upper > lower)
                {
                    upperRow[i] = 1;
                    upper--;
                }
                else
                {
                    lowerRow[i] = 1;
                    lower--;
                }
            }
        }
        
        if (upper != 0 || lower != 0)
            return { };
        else
            return {upperRow, lowerRow};
    }
};
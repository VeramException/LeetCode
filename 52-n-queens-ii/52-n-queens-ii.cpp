class Solution
{
public:
    int n;
    unordered_set<int> cols;
    unordered_set<int> posDiag;   // 'row+col' stays constant
    unordered_set<int> negDiag;   // 'row-col' stays constant
    
    int res;
    
    int totalNQueens(int siz)
    {
        n = siz;
        backtrack(0);
        return res;
    }
    
    void backtrack(int r)
    {
        if (r == n)
        {
            res++;
            return;
        }
        
        for (int c=0; c<n; c++)
        {
            if (cols.count(c) || posDiag.count(r+c) || negDiag.count(r-c))
                continue;
            
            cols.insert(c);
            posDiag.insert(r+c);
            negDiag.insert(r-c);
            
            backtrack(r+1);
            
            cols.erase(c);
            posDiag.erase(r+c);
            negDiag.erase(r-c);           
        }
    }
};
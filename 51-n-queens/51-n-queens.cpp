class Solution
{
    public:
    int n;
    unordered_set<int> cols;
    unordered_set<int> posDiag;   // 'row+col' stays constant
    unordered_set<int> negDiag;   // 'row-col' stays constant
    
    vector<string> board;
    vector<vector<string>> res;
    
    vector<vector<string>> solveNQueens(int siz)
    {
        n = siz;
        board.resize(n, string(n, '.'));
        backtrack(0);
        return res;
    }
    
    void backtrack(int r)
    {
        if (r == n)
        {
            res.push_back(board);
            return;
        }
        
        for (int c=0; c<n; c++)
        {
            if (cols.count(c) || posDiag.count(r+c) || negDiag.count(r-c))
                continue;
            
            cols.insert(c);
            posDiag.insert(r+c);
            negDiag.insert(r-c);            
            board[r][c] = 'Q';
            
            backtrack(r+1);
            
            cols.erase(c);
            posDiag.erase(r+c);
            negDiag.erase(r-c);            
            board[r][c] = '.';            
        }
    }
};
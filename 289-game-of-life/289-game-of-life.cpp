class Solution
{
    public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<int>> neighbors = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        // If a cell is '1'
        // ========================
        // neighbors   < 2, it dies
        // neighbors [2,3], it lives
        // neighbors   > 3, it dies
        
        // If a cell is '0'
        // ========================
        // neighbors   = 3, it becomes '1
        
        vector<vector<int>> nextBoard(rows, vector<int>(cols, 0));
        for (int r=0; r<rows; r++)
        {
            for (int c=0; c<cols; c++)
            {
                int live = 0;                
                for(vector<int> n: neighbors)
                {
                    int rr = r+n[0];
                    int cc = c+n[1];
                    if (rr >= 0 && rr < rows && cc >=0 && cc < cols)
                        live += board[rr][cc];
                }
                if (board[r][c] == 0 && live == 3)
                    nextBoard[r][c] = 1;
                else if (board[r][c] == 1)
                {
                    if (live < 2 || live > 3)
                        nextBoard[r][c] = 0;
                    else
                        nextBoard[r][c] = 1;
                }
            }
        }
        
        for (int r=0; r<rows; r++)
            for (int c=0; c<cols; c++)
                board[r][c] = nextBoard[r][c];
    }
};

class Solution
{
    public:
    int rows, cols;
    vector<vector<char>> board;
    string word;    
    
    bool exist(vector<vector<char>>& b, string w)
    {
        board = b;
        word = w;
        rows = board.size();
        cols = board[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int r=0; r<rows; r++)
            for (int c=0; c<cols; c++)
                if (dfs(r, c, 0, visited))
                    return true;
        
        return false;
    }
    
    bool dfs(int r, int c, int i, vector<vector<bool>>& visited)
    {
        if (i == word.size())
            return true;
        
        if (r < 0 || r >= rows || c < 0 || c >= cols ||     // out of bounds
            board[r][c] != word[i] ||                       // no match
            visited[r][c])
        {
            return false;
        }
        
        visited[r][c] = true;
        
        bool result = dfs (r+1, c+0, i+1, visited) ||
                      dfs (r-1, c+0, i+1, visited) ||
                      dfs (r+0, c+1, i+1, visited) ||
                      dfs (r+0, c-1, i+1, visited);
        
        visited[r][c] = false;
        
        return result;
    }
};
class Solution
{
    public:
    vector<string> res;
    
    void generateParenthesisUtil(int n, int open, int close, string s)
    {
        // finished 'n' open and closing braces.
        if (open == n && close == n)
        {
            res.push_back(s);
            return;
        }

        if (open < n) // we can open a brace only if there are still open braces remaining
            generateParenthesisUtil(n, open+1, close, s+"(");

        if (close < open) // we can close a brace only when we already opened enough braces
            generateParenthesisUtil(n, open, close + 1, s+")");
    }

    vector<string> generateParenthesis(int n)
    { 
        generateParenthesisUtil(n, 0, 0, "");
        return res;
    }
};
class Solution
{
    public:
    int scoreOfParentheses(string s)
    {
        int res = 0;
        int layers = 0;
        
        for (int i=0; i<s.size(); i++)
        {
            if (s[i] == '(')
                layers++;
            else
            {
                layers--;
                if (s[i-1] == '(')
                    res += pow(2, layers);
            }
        }
        
        return res;
    }
};
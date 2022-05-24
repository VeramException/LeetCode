class Solution
{
    public:
    int longestValidParentheses(string s)
    {
        int res = 0;
        int open = 0;
        int close = 0;
        
        // Left to Right
        for (int i=0; i<s.size(); i++)
        {
            if (s[i] == '(')
                open++;
            else
                close++;
            
            if (open == close)
                res = max (res, 2*close);
            else if (close > open)
            {
                open  = 0;
                close = 0;
            }
        }
        
        // Right to Left
        open  = 0;
        close = 0;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i] == '(')
                open++;
            else
                close++;
            
            if (open == close)
                res = max (res, 2*close);
            else if (open > close)
            {
                open  = 0;
                close = 0;
            }
        }
        
        return res;
    }
};

/*
class Solution
{
    public:
    int longestValidParentheses(string s)
    {
        int res = 0;
        
        stack<int> st;
        st.push(-1);
        
        for(int i=0; i<s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {   
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                    res = max(res, i-st.top());
            }
        }
        
        return res;
    }
};
*/
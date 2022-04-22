class Solution
{
    public:
    int myAtoi(string s)
    {
        long res = 0;
        int indicator = 1;
        
        int i = s.find_first_not_of(' ');
        if (i != -1) 
        {
            if (s[i] == '-' || s[i] == '+')
                indicator = (s[i++] == '-')? -1: 1;
            
            while (i<s.size() && isdigit(s[i]))
            {
                res = res*10 + (s[i++]-'0');
                
                if (res*indicator <= INT_MIN) return INT_MIN;
                if (res*indicator >= INT_MAX) return INT_MAX;
            }
        }
        
        return indicator * res;
    }
};
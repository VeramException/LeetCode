class Solution
{
    public:
    string removeKdigits(string num, int k)
    {
        string res;
        
        for (char c: num)
        {
            while (res != "" && res.back() > c && k > 0)
            {
                res.pop_back();
                k--;
            }
            
            if (res != "" || c != '0')  // We don't want to add '0' at the beginning
                res += c;
        }
        
        while(res != "" && k--)        // If there are any more 'k' left
            res.pop_back();
        
        return (res == "")? "0": res;
    }
};
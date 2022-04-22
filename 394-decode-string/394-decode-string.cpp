class Solution
{
    public:
    string decodeString(string s)
    {
        int pos = 0;
        return decodeStringUtil(s, pos);
    }
    
    
    string decodeStringUtil(string& s, int& pos)
    {
        int num = 0;
        string word = "";
        
        while (pos < s.size())
        {
            if (isdigit(s[pos]))
            {
                num = num*10 + (s[pos] - '0');
            }
            else if (s[pos] == '[')
            {
                string currWord = decodeStringUtil(s, ++pos);
                while (num > 0) // dont do num--, because it can become ''-0'
                {
                    word += currWord;
                    num--;
                }
            }
            else if (s[pos] == ']')
            {
                return word;
            }
            else
            {
                word += s[pos];
            }            
            pos++;
        }
        
        return word;
    }
};
class Solution
{
    public:
    string longestCommonPrefix(vector<string>& words)
    {
        string res;
        
        bool noMismatch = true;
        for (int i=0; i<words[0].size() & noMismatch; i++)
        {
            char c = words[0][i];                
            for (string& word: words)
            {
                if (i >= word.size() || word[i] != c)
                {
                    noMismatch = false;
                    break;
                }
            }
            if (noMismatch)
                res += c;
        }
        
        return res;
    }
};
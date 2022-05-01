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
            for (int j=0; j<words.size() && noMismatch; j++)
                if (i >= words[j].size() || words[j][i] != c)
                    noMismatch = false;

            if (noMismatch) res += c;
        }
        return res;
    }
};
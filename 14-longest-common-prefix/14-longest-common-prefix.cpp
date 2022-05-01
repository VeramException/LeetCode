class Solution
{
    public:
    string longestCommonPrefix(vector<string>& words)
    {     
        string res;
        bool noMismatch = true;
        for (int i=0; i<words[0].size() & noMismatch; i++)
        {
            for (int j=1; j<words.size() && noMismatch; j++)
                if (i >= words[j].size() || words[j][i] != words[0][i])
                    noMismatch = false;

            if (noMismatch)
                res += words[0][i];
        }
        return res;
    }
};
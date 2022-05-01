class Solution
{
    public:
    string longestCommonPrefix(vector<string>& words)
    {
        string res;
        
        bool good = true;
        for (int i=0; good && i<words[0].size(); i++)
        {
            char c = words[0][i];                
            for (string& word: words)
            {
                if (i >= word.size() || word[i] != c)
                {
                    good = false;
                    break;
                }
            }
            if (good == true)
                res += c;
        }
        
        return res;
    }
};
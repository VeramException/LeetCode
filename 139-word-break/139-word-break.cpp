class Solution
{
    public:
    bool wordBreak(string s, vector<string>& wordDict)
    {        
        int n = s.size();
        vector<bool> DP(n+1, false);
        DP[n] = true;
        
        for (int i=n-1; i>=0; i--)
        {
            for (string word: wordDict)
            {
                if (n-i < word.size())
                    continue;
                
                if (s.substr(i, word.size()) == word)
                    DP[i] = DP[i+word.size()];
                
                if (DP[i] == true)
                    break;
            }
        }
        
        return DP[0];
    }
};
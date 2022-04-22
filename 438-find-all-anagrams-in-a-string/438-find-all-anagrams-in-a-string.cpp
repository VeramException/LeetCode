#define NO_OF_CHARS 256

class Solution
{
    public:
    
    vector<int> findAnagrams(string full, string pattern)
    {        
        if (pattern.size() > full.size())
            return {};
        
        vector<int> res;
        
        int countPattern[256]       = {0};
        int countCurrentWindow[256] = {0};
        
        for (int i = 0; i < pattern.size(); i++)
        {
            countPattern[pattern[i]]++;
            countCurrentWindow[full[i]]++;
        }
        
        for (int i = pattern.size(); i < full.size(); i++)
        {
            if (isSame(countPattern, countCurrentWindow))
                res.push_back(i - pattern.size());

            countCurrentWindow[full[i]]++;
            countCurrentWindow[full[i - pattern.size()]]--;
        }
        
        // check last window
        if (isSame(countPattern, countCurrentWindow))
                res.push_back(full.size() - pattern.size());
        
        return res;
    }
    
    bool isSame(int a[], int b[])
    {
        for (int i=0; i<256; i++)
            if (a[i] != b[i])
                return false;
        return true;
    }
};
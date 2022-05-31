class Solution
{
    public:
    unordered_set<string> combs;
    
    bool hasAllCodes(string s, int k)
    {
        int l = 0, r = 0;        
        while (r < s.size())
        {
            if (r - l + 1 == k)
                combs.insert(s.substr(l++, k));
            r++;
        }        
        return (pow(2,k)==combs.size());
    }
};
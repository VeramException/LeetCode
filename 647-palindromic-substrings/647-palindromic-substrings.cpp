class Solution
{
    public:    
    int countSubstrings(string s)
    {
        int counter = 0;
        int n = s.size();
        
        for (int i=0; i<n; i++)
        {
            // odd length palindromes
            for (int l=i, r=i; l>=0 && r<n && s[l] == s[r]; l--, r++)
                counter++;
            
            // even length palindromes
            for (int l=i, r=i+1; l>=0 && r<n && s[l] == s[r]; l--, r++)
                counter++;
        }
        
        return counter;
    }
};
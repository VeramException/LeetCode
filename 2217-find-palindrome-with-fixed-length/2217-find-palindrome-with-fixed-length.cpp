class Solution
{
    public:
    vector<long long> kthPalindrome(vector<int>& queries, int length)
    {   
        vector<long long> res;
        for (auto const q: queries)
            res.push_back(getIthPalindrome(q, length));
        return res;
    }
    
    long long getIthPalindrome(int i, int length)
    {
        long long res;
        
        // We only think of half-number.
        // i.e., for EVEN -> 123321,  we only think of first 3 digits. It can be from 99+1 to 999
        // i.e., for ODD  -> 1234321, we only think of first 4 digits. It can be from 999+1 to 9999
        
        long long minVal = 0;
        long long maxVal = 0;
        
        int minDigits = 0;
        int maxDigits = 0;
        
        if (length%2 == 0)
        {
            minDigits = length/2 - 1;
            maxDigits = length/2;
        }
        else
        {
            minDigits = length/2;
            maxDigits = length/2 + 1;
        }
        
        while (minDigits-- > 0)
            minVal = minVal*10 + 9;
        while (maxDigits-- > 0)
            maxVal = maxVal*10 + 9;
        
        if (i > (maxVal - minVal))
            return -1;
        
        string s1 = to_string(minVal + i);
        string s2 = (length%2 == 0)? s1: s1.substr(0, length/2);        
        reverse(s2.begin(), s2.end());
                
        return stoll(s1+s2);
    }
};
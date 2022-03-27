class Solution
{
    public:
    long long minVal;
    long long maxVal;
    
    vector<long long> kthPalindrome(vector<int>& queries, int length)
    {
        // We only think of half-number.
        // i.e., for EVEN -> 123321,  we only think of first 3 digits. It can be from 99+1 to 999   (minVal+1 -> maxVal)
        // i.e., for ODD  -> 1234321, we only think of first 4 digits. It can be from 999+1 to 9999 (minVal+1 -> maxVal)

        int minDigits = (length%2 == 0)? (length/2 - 1): (length/2);
        int maxDigits = (length%2 == 0)? (length/2): (length/2 + 1);
        
        while (minDigits-- > 0) minVal = minVal*10 + 9;
        while (maxDigits-- > 0) maxVal = maxVal*10 + 9;

        vector<long long> res;
        for (auto const k: queries)
            res.push_back(getkthPalindrome(k, length));
        return res;
    }
    
    long long getkthPalindrome(int k, int length)
    {   
        if (k > (maxVal - minVal))
            return -1;
        
        string s1 = to_string(minVal + k);
        string s2 = (length%2 == 0)? s1: s1.substr(0, length/2);        
        reverse(s2.begin(), s2.end());
                
        return stoll(s1+s2);
    }
};
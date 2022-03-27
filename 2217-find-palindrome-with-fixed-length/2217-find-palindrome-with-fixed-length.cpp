class Solution
{
    public:
    long long minVal;
    long long maxVal;
    
    vector<long long> kthPalindrome(vector<int>& queries, int length)
    {
        vector<long long> res;
        calculateMinMaxVals(length);
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
    
    void calculateMinMaxVals(int length)
    {
        int minDigits = (length%2 == 0)? (length/2 - 1): (length/2);
        int maxDigits = (length%2 == 0)? (length/2): (length/2 + 1);
        
        while (minDigits-- > 0) minVal = minVal*10 + 9;
        while (maxDigits-- > 0) maxVal = maxVal*10 + 9;
    }
};
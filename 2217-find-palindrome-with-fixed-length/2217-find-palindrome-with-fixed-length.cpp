class Solution
{
    public:
    vector<long long> kthPalindrome(vector<int>& queries, int length)
    {   
        vector<long long> res;
        for (auto const k: queries)
            res.push_back(getkthPalindrome(k, length));
        return res;
    }
    
    long long getkthPalindrome(int k, int length)
    {
        // We only need to find the first half of the number. Then we can simple reverse the 1st half digits to get the 2nd half.
        
        // For example, 
        // if you need 1st 4-digit palindrome -> the first half is 9+1 = "10", The 2nd half is reverse of it "01"
        // if you need 3rd 4-digit palindrome -> the first half is 9+3 = "12", The 2nd half is reverse of it "21"
        
        // For even n-digits, we only need to think of first_half i.e., n/2
        // Eg: 123321 -> 123, 321 (reverse of 123)
        
        // For even n-digits, we only need to think of first_half+1 , i.e., n/2 + 1
        // Eg: 1234321 -> 1234, 321 (reverse of 123)
        
        // Limits of a n-digit palindrome
        // Even for limits, we only should think of first half digits.
        // Eg: if you need a 6 digit palindrome, the first 3 digits can be from 99+1 to 999   (minVal+1 -> maxVal)
        // Eg: if you need a 7 digit palindrome, the first 4 digits can be from 999+1 to 9999 (minVal+1 -> maxVal)

        int minDigits = (length%2 == 0)? (length/2 - 1): (length/2);
        int maxDigits = (length%2 == 0)? (length/2): (length/2 + 1);
        
        long long minVal = 0;
        long long maxVal = 0;
        
        while (minDigits-- > 0) minVal = minVal*10 + 9;
        while (maxDigits-- > 0) maxVal = maxVal*10 + 9;
        
        if (k > (maxVal - minVal))
            return -1;
        
        string s1 = to_string(minVal + k);
        string s2 = (length%2 == 0)? s1: s1.substr(0, length/2);        
        reverse(s2.begin(), s2.end());
                
        return stoll(s1+s2);
    }
};
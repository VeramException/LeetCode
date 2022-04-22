class Solution
{
    public:
    
    string digits[20] = {"Zero",
                         "One",
                         "Two",
                         "Three",
                         "Four",
                         "Five",
                         "Six",
                         "Seven",
                         "Eight",
                         "Nine",
                         "Ten",
                         "Eleven",
                         "Twelve",
                         "Thirteen",
                         "Fourteen",
                         "Fifteen",
                         "Sixteen",
                         "Seventeen",
                         "Eighteen",
                         "Nineteen"};
    
    string tens[10] = {"Zero",
                       "Ten",
                       "Twenty",
                       "Thirty",
                       "Forty",
                       "Fifty",
                       "Sixty",
                       "Seventy",
                       "Eighty",
                       "Ninety"};
    
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";        
        string res = numberToWordsUtil(num);
        return res.substr(1); // res[0] will be space
    }
    
    string numberToWordsUtil(int num)
    {
        if (num >= 1000000000) // >= 1 Billion
        {
            return numberToWordsUtil(num / 1000000000) + " Billion" + numberToWordsUtil(num % 1000000000);
        }
        else if (num >= 1000000) // >= 1 Million
        {
            return numberToWordsUtil(num / 1000000) + " Million" + numberToWordsUtil(num % 1000000);
        }
        else if (num >= 1000) // >= 1 Thousand
        {
            return numberToWordsUtil(num / 1000) + " Thousand" + numberToWordsUtil(num % 1000);
        }
        else if (num >= 100) // >= 100
        {
            return numberToWordsUtil(num / 100) + " Hundred" + numberToWordsUtil(num % 100);
        }
        else if (num >= 20)
        {
            return " " + tens[num/10] + numberToWordsUtil(num % 10);
        }
        else if (num >= 1)
        {
            return " " + digits[num];
        }
        else // 0
        {
            return "";
        }
    }
};





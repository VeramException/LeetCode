// I  - 1
// V  - 5
// IX - 9
// X  - 10
// XL - 40
// L  - 50
// XC - 90
// C  - 100
// CD - 400
// D  - 500
// CM - 900
// M  - 1000
    
class Solution 
{
    public:    
    string intToRoman(int num)
    {
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};        
        string hdrs[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thos[] = {"", "M", "MM", "MMM"};
        
        return (thos[num/1000] + hdrs[(num%1000)/100] + tens[(num%100)/10] + ones[num%10]);
    }
};

// num            = 3526
// (num/1000)     = 3
// (num%1000)/100 = 5
// (num%100)/10   = 2
// (num%10)       = 6
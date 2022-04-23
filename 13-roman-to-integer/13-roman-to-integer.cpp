class Solution
{
    public:
    int romanToInt(string s)
    {
        unordered_map<char, int> m1;
        m1['I'] = 1;
        m1['V'] = 5;
        m1['X'] = 10;
        m1['L'] = 50;
        m1['C'] = 100;
        m1['D'] = 500;
        m1['M'] = 1000;
        
        unordered_map<string, int> m2;
        m2["IV"] = 4;
        m2["IX"] = 9;
        m2["XL"] = 40;
        m2["XC"] = 90;
        m2["CD"] = 400;
        m2["CM"] = 900;
        
        int res = 0, i=0;
        while (i < s.size())
        {
            if (i <= s.size()-2 && m2.count(s.substr(i,2)))
            {
                res += m2[s.substr(i,2)];
                i = i+2;
            }
            else
                res += m1[s[i++]];
        }
        return res;
    }
};
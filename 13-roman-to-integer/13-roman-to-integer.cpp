class Solution
{
    public:
    int romanToInt(string s)
    {
        unordered_map<char, int> m1 = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};        
        unordered_map<string, int> m2 = {{"IV",4}, {"IX",9}, {"XL",40}, {"XC",90}, {"CD",400}, {"CM",900}};
        
        int i=0, res=0;
        while (i < s.size())
        {
            if (i+1 < s.size() && m2.count(s.substr(i,2)))
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
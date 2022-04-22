class Solution
{
    public:
    string digits;
    unordered_map<char, vector<char>> m;
    vector<string> res;
    
    vector<string> letterCombinations(string s)
    {
        digits = s;
        
        if (digits == "")
            return res;
        
        m['2'] = {'a','b','c'};
        m['3'] = {'d','e','f'};
        m['4'] = {'g','h','i'};
        m['5'] = {'j','k','l'};
        m['6'] = {'m','n','o'};
        m['7'] = {'p','q','r','s'};
        m['8'] = {'t','u','v'};
        m['9'] = {'w','x','y','z'};
        
        letterCombinationsUtil("", 0);
        return res;
    }
    
    void letterCombinationsUtil(string prefix, int index)
    {
        if (index >= digits.size())
        {
            res.push_back(prefix);
            return;
        }
        
        for (char c: m[digits[index]])
            letterCombinationsUtil (prefix+c, index+1);
    }
};
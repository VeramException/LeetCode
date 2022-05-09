class Solution
{
    public:
    vector<string> res;
    unordered_map<char, vector<char>> m;
        
    vector<string> letterCombinations(string s)
    {
        m['2'] = {'a','b','c'};
        m['3'] = {'d','e','f'};
        m['4'] = {'g','h','i'};
        m['5'] = {'j','k','l'};
        m['6'] = {'m','n','o'};
        m['7'] = {'p','q','r','s'};
        m['8'] = {'t','u','v'};
        m['9'] = {'w','x','y','z'};
        
        letterCombinationsUtil(s, 0, "");
        
        return res;
    }
    
    void letterCombinationsUtil(string& s, int i, string currRes)
    {
        if (i == s.size() && currRes != "")
        {
            res.push_back(currRes);
            return;
        }
        
        for (char c: m[s[i]])
            letterCombinationsUtil(s, i+1, currRes+c);
    }
};
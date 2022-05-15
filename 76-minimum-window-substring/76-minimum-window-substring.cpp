class Solution 
{
    public:
    
    bool isSubset(unordered_map<char, int>& s_map, unordered_map<char, int>& t_map)
    {
        for (auto const& [c, c_count] : t_map)
            if (s_map.count(c) == 0 || s_map[c] < t_map[c])   // we can write "s_map[c] < c_count", but just to be clear during code reading
                return false;

        return true;
    }
    
    string minWindow(string s, string t)
    {
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
    
        // load t_map
        for (char c : t)
            t_map[c]++;
    
        int windowSize = 0;
        int savedi = 0;
        int savedj = 0;
    
        int i = 0;
        int j = 0;
        s_map[s[j]] = 1;
        while (j < s.size())
        {
            // check if we already found the substring.
            // If found, and if the previously saved windowSize
            // is larger than this one, save this one.
            if (isSubset(s_map, t_map))
            {
                if (windowSize == 0 || (windowSize > (j - i + 1)))
                {
                    windowSize = (j - i) + 1;
                    savedi = i;
                    savedj = j;
                }
    
                // Before we forward 'i', let's remove it from s_map if it exists.
                if (s_map.count(s[i]) > 0 && --s_map[s[i]] == 0)
                    s_map.erase(s_map.find(s[i]));
                i++;
                continue;
            }
    
            if (j++ == s.size()-1) continue;
            // if this character 's[j]' is available in t,
            // then place it in the s_map.
            
            if (t_map.count(s[j]) > 0)
                s_map[s[j]]++;
        }
    
        if (windowSize > 0)
            return s.substr(savedi, windowSize);
        else
            return "";
    }
};
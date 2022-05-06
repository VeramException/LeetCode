class Solution
{
    public:
    string removeDuplicates(string s, int k)
    {
        vector<pair<char, int>> st; // simulate stack with vector
        
        for (char c: s)
        {
            if (st.empty() || st.back().first != c)
            {
                st.push_back({c, 1});
                    
            }
            else if (++st.back().second == k)
                st.pop_back();                
        }
        
        string res;
        for (auto c_pair: st)
        {
            string val(c_pair.second, c_pair.first);
            res += val;
        }
        return res;
    }
};
class Solution
{
    public:
    string removeDuplicates(string s, int k)
    {
        vector<pair<char, int>> st; // simulate stack with vector
        
        for (char c: s)
        {
            if (!st.empty() && st.back().first == c)
            {
                st.back().second++;
                if (st.back().second == k)
                    st.pop_back();
            }
            else
                st.push_back({c, 1});
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
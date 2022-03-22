class Solution
{
    public:
    int lengthLongestPath(string input)
    {
        stringstream ss(input);
        string token;
        vector<int> len;
        int ans = 0;
        
        while (getline(ss, token, '\n'))
        {
            len.push_back(0);
            int l = count(token.begin(), token.end(), '\t');
            len[l] = token.substr(l).length();
            if (token.find('.') != string::npos)
                ans = max(ans, accumulate(len.begin(), len.begin()+l+1, 0) + l);
        }        
        return ans;
    }
};

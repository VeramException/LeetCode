class Solution
{
    public:
    string removeDuplicateLetters(string s)
    {
        vector<int> count(256, 0);
        vector<bool> visited(256, false);
        
        for (char c : s)
            count[c]++;
        
        string result = "0";
        for (char c : s)
        {
            count[c]--;
            
            if (visited[c]) 
                continue;
            
            // Basically using 'result' as a monotonic increasing stack
            while (c < result.back() && count[result.back()])
            {
                visited[result.back()] = false;
                result.pop_back();
            }
            
            result += c;
            visited[c] = true;
        }
        return result.substr(1);
}
};
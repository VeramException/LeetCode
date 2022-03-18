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
            
            // Logic: if there will be another 'result.back()' that we can use in future,
            //        and if result.back() is alphabetically larger, then let's remove it from 'result'.
            //        beause we can add it again to result in future anyway
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
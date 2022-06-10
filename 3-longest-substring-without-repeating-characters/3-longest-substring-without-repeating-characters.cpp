class Solution
{
    public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> visited; // O(1) - Because it contains only a maximum of 128 characters
                
        int l = 0;
        int r = 0;
        int n = s.size();
        
        int maxDistance = 0;
        
        while(r<n)
        {
            if(visited.count(s[r]) == 0)
            {
                visited.insert(s[r]);
                maxDistance = max(maxDistance, r-l+1);
                r++;
            }
            else
            {
                visited.erase(s[l]);
                l++;
            }
        }    
        return maxDistance;
    }
};
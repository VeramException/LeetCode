class Solution
{
    public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> set; 
                
        int l = 0;
        int r = 0;
        int n = s.size();
        
        int maxDistance = 0;
        
        while(r<n)
        {
            if(set.find(s[r]) == set.end())
            {
                set.insert(s[r]);
                maxDistance = max(maxDistance, r-l+1);
                r++;
            }
            else
            {
                set.erase(s[l]);
                l++;
            }
        }    
        return maxDistance;
    }
};
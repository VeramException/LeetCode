class Solution
{
    public:
    int minDeletions(string s)
    {
        vector<int> freq(26,0);        
        for (char c: s)
            freq[c - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());
        
        int deleteCount = 0;
        int maxFreqAllowed = s.size();
        for (int i=0; i<26; i++)
        {
            if (freq[i] > maxFreqAllowed)
            {
                deleteCount += freq[i] - maxFreqAllowed;
                freq[i] = maxFreqAllowed;
            }
            maxFreqAllowed = max(0, freq[i]-1);
        }
        
        return deleteCount;
    }
};
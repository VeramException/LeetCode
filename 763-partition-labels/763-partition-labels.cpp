class Solution
{
    public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> m;
        for(int i=0; i<s.size(); i++)
            m[s[i]] = i;              // It is enough to store just the last occurence of s[i].
        
        vector<int> res;
        int farthest_i = 0;
        int prev_partition_i = -1;
        
        for (int i=0; i<s.size(); i++)
        {
            farthest_i = max(farthest_i, m[s[i]]);
            
            if (farthest_i == i)
            {
                res.push_back(i - prev_partition_i);
                prev_partition_i = i;
            }
        }
        
        
        return res;
    }
};
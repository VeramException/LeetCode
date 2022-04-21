// Count the contribution of each character.
// (left+1)*(right+1) = number of combinations.

class Solution
{
    public:
    int uniqueLetterString(string s)
    {
        int N = s.size();
        
        unordered_map<char, vector<int>> m;        
        for (int i=0; i<N; i++)
            m[s[i]].push_back(i);
        
        int sum = 0;
        for (auto const& [c, indices]: m)
        {
            for (int i=0; i<indices.size(); i++)
            {
                int left  = (i == 0)?                (indices[i]+1):   (indices[i]   - indices[i-1]);
                int right = (i == indices.size()-1)? (N - indices[i]): (indices[i+1] - indices[i]);
                
                sum += left * right;
            }
        }
        
        return sum;
    }
};
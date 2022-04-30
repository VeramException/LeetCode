class Solution
{
    public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {     
        for(vector<int>& p: dominoes)
            sort(p.begin(), p.end());
        
        int pairs = 0;
        
        unordered_map<string, int> m;
        
        for (int i=0; i<dominoes.size(); i++)
        {
            string key = to_string(dominoes[i][0]) + "," + to_string(dominoes[i][1]);
            pairs += m[key]++;
        }
        
        return pairs;
    }
};
class Solution
{
    public:
    vector<vector<int>> res;
    vector<int> currComb;
    
    vector<vector<int>> combine(int n, int k)
    {   
        backtrack(1, n, k);
        return res;
    }
    
    void backtrack(int start, int n, int k)
    {
        if (currComb.size() == k)
        {
            res.push_back(currComb);
            return;
        }
        
        for (int i=start; i<=n; i++)
        {
            currComb.push_back(i);
            backtrack(i+1, n, k);
            currComb.pop_back();
        }
    }
};
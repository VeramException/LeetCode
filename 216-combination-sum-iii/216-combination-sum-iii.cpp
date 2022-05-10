class Solution
{
    public:
    vector<vector<int>> result;
    
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> currentComb;
        combinationSum3Util(k, n, currentComb);
        return result;
    }
    
    void combinationSum3Util(int k, int n, vector<int> currentComb)
    {
        if (currentComb.size() == k && n == 0)
            result.push_back(currentComb);
        
        //if (currentComb.size() < k)
        for (int i=currentComb.empty()? 1: currentComb.back()+1 ; i<=9; i++)
        {
            if (n-i < 0)
                break;
            
            currentComb.push_back(i);
            combinationSum3Util(k, n-i, currentComb);
            currentComb.pop_back();
        }
    }
};
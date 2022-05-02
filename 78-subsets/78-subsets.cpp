class Solution
{
    public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res = {{}};
        
        for (int num: nums)
        {
            int siz = res.size();
            for (int i=0; i<siz; i++)
            {
                vector<int> newSubset = res[i];
                newSubset.push_back(num);
                res.push_back(newSubset);
            }
        }
        
        return res;
    }
};
class Solution
{
    public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
    {   
        unordered_set<int> num1_set (nums1.begin(), nums1.end());
        unordered_set<int> num2_set (nums2.begin(), nums2.end());
     
        vector<vector<int>> ans(2);
        
        for (int n1: num1_set)
            if (num2_set.find(n1) == num2_set.end())
                ans[0].push_back(n1);

        for (int n2: num2_set)
            if (num1_set.find(n2) == num1_set.end())
                ans[1].push_back(n2);
        
        return ans;
    }
};
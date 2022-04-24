class Solution
{
    public:
    void rotate(vector<int>& nums, int k2)
    {
        // 3-lines solution.
        // https://leetcode.com/problems/rotate-array/discuss/54308/Simple-and-Most-elegant-logic
        
        k2 = k2%nums.size();
        int k1 = nums.size()-k2;
        
        reverse(nums.begin(),  nums.begin()+k1);
        reverse(nums.end()-k2, nums.end());
        reverse(nums.begin(),  nums.end());
    }
};
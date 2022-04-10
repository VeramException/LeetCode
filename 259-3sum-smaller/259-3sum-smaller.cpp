class Solution
{
    public:
    int threeSumSmaller(vector<int>& nums, int target)
    {
        int count = 0;
        
        if (nums.size() < 3)
            return count;
        
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size()-2; i++)
        {
            int j = i+1;
            int k = nums.size()-1;
            
            while (j < k)
            {
                while (j<k && nums[i]+nums[j]+nums[k] >= target)
                    k--;
                 
                count = count + (k-j);
                j++;
            }
        }
        
        return count;
    }
};
class Solution
{
    public:
    bool canJump(vector<int>& nums)
    {
        if (nums.size() == 1)
            return true;
        
        for (int i=nums.size()-2; i>=0; i--)
        {
            if (nums[i] == 0)
            {
                int posToZero = 0;
                while (i >=0 && nums[i] <= posToZero)
                {
                    i--;
                    posToZero++;
                }
                
                if (i < 0)
                    return false;
            }
        }
        
        return true;
    }
};
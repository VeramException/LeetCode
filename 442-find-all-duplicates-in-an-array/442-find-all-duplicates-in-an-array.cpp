class Solution
{
    public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        nums.push_back(0);
        
        vector<int> res;        
        for (int i=0; i<nums.size()-1; i++)
        {
            int index = abs(nums[i]);
            
            if (nums[index] < 0)
            {
                res.push_back(index);
            }
            else
            {
                if (nums[index] == 0)
                    nums[index] = INT_MIN;
                else
                    nums[index] = -abs(nums[index]);
            }
        }
        return res;
    }
};

// [4, 3, 2, 7, 8, 2, 3, 1, 0]

// [     -2,-7,-8,      -1,  ]
// [0, 1, 2, 3, 4, 5, 6, 7, 8]
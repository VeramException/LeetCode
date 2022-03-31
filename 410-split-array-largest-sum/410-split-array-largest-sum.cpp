class Solution
{
    public:
    int splitArray(vector<int>& nums, int m)
    {
        int left = INT_MIN;
        int right = 0;        
        for (int num: nums)
        {
            left = max(left, num);
            right += num;    
        }
        
        while (left < right)
        {
            int mid = (left+right)/2;
            if(isPossibleLargestSum(nums, m-1, mid))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
    
    bool isPossibleLargestSum(vector<int>& nums, int cuts, int maxSum)
    {
        int subArraySum = 0;
        int i = 0;
        
        while (cuts >=0 && i<nums.size())
        {
            if (subArraySum + nums[i] <= maxSum)
            {
                subArraySum += nums[i];
                i++;
            }
            else
            {
                cuts--;
                subArraySum = 0;
            }
        }
        
        if (cuts < 0)
            return false;
        return true;
    }
};
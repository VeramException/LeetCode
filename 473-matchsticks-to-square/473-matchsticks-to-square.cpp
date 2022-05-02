class Solution
{
    public:
    bool makesquare(vector<int>& sticks)
    {
        return canPartitionKSubsets(sticks, 4);
    }
    
    // The below is basically - "Leetcode 698. Partition to K Equal Sum Subsets"
    
    unordered_map<int, unordered_map<int, int>> cache; // [start_index, visited, true/false]
    
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {        
        int sum = accumulate(nums.begin(), nums.end(), 0);        
        if (sum%k != 0) return false;
       
        //vector<int> visited(nums.size(), false);
        int visited = 0; // Use this (bit-masking) instead of vector to avoid TLE.

        return canPartitionBackTrack(nums, visited, (sum/k), 0, k, 0);
    }
    
    bool canPartitionBackTrack(vector<int>& nums, int visited, int maxSum, int start_index, int k, int currSum)
    {
        if (k == 1)
            return true;
        
        if(currSum > maxSum)
        {
            cache[start_index][visited] = false;
            return false;
        }
        
        if (cache.count(start_index) > 0 && cache[start_index].count(visited) > 0)
            return cache[start_index][visited];
        
        // If we built one subset, let's see if we can build the next subset
        if (currSum == maxSum) 
            return canPartitionBackTrack (nums, visited, maxSum, 0, k-1, 0);
           
        for (int i=start_index; i<nums.size(); i++)
        {
            //if (!visited[i])
            if (!(visited>>i & 1))
            {
                //visited[i] = true;
                visited = visited | (1 << i);
                
                if (canPartitionBackTrack(nums, visited, maxSum, i+1, k, currSum + nums[i]))
                    return true;
                
                //visited[i] = false;
                visited = visited & ~(1 << i);
            }
        }
        
        cache[start_index][visited] = false;
        return false;
    }
};
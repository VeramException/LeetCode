// Watch this video 5:55 to get clear understanding of how we can skip entire level.
// https://www.youtube.com/watch?v=dJ7sWiOoK7g

// Time  - O(n)
// Space - O(1)
class Solution 
{    
    public:
    
    int jump(vector<int>& nums)
    {
        int minJumps = 0;
        
        int l = 0, r = 0;        
        while(r < nums.size()-1)
        {
            int farthest = 0;
            for (int i = l; i <= r; i++)
                farthest = max(farthest, i+nums[i]);
            
            // Next level
            l = r + 1;
            r = farthest;            
            minJumps++;
        }        
        return minJumps;
    }
};
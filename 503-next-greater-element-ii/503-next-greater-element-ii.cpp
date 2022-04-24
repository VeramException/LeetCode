class Solution
{
    public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> nextGreater(n, -1);
        
        stack<pair<int,int>> s;
        for (int i=0; i< 2*n; i++)
        {
            int j=i%n; // 0%3=[0], 1%3=[1], 2%3=[2], 3%3=[0], 4%3=[1], 5%3=[2]    //--> this will simulate arr=arr+arr
            
            while(!s.empty() && s.top().first < nums[j])
            {
                nextGreater[s.top().second] = nums[j];
                s.pop();
            }
            s.push({nums[j],j});
        }
        
        return nextGreater;
    }
};
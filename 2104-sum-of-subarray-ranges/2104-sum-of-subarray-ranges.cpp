class Solution
{
    public:
    long long subArrayRanges(vector<int>& nums)
    {
        int N = nums.size();
        
        vector<long long> minVals(N);
        vector<long long> maxVals(N);
        
        sumSubarrayMins(nums, minVals);
        sumSubarrayMaxs(nums, maxVals);
        
        long long sum = 0;
        for (int i=0; i<N; i++)
            sum = sum + (maxVals[i]-minVals[i])*nums[i];

        return sum;
    }
       
    void sumSubarrayMins(vector<int>& nums, vector<long long>& minVals)
    {
        int N = nums.size();
        
        vector<int> left(N);    // to hold the next smaller element on the left
        vector<int> right(N);   // to hold the next smaller element on the right
        
        // Left
        stack<int> s;   // Monotonic Stack --> store the latest smallest
        for (int i=0; i<N; i++)
        {
            while (!s.empty() && nums[i] < nums[s.top()])   // ***mind "<" for left***
                s.pop();
            
            if (!s.empty())
                left[i] = i - s.top();
            else
                left[i] = i+1;
            
            s.push(i);
        }
       
        // Optimization: Here we can possibly clear the old stack and re-use it.
        // We can also write this for clearing the stack.
        // st=stack<int>();
        
        // Right
        stack<int> st;   // Monotonic Stack --> store the latest smallest
        for (int i=N-1; i>=0; i--)
        {
            while (!st.empty() && nums[i] <= nums[st.top()])   // ***mind "<=" for right***
                st.pop();
            
            if (!st.empty())
                right[i] = st.top() - i;
            else
                right[i] = N-i;
            
            st.push(i);
        }
        
        for (int i=0; i<N; i++)
            minVals[i] = (left[i] * right[i]);
    }
    
    void sumSubarrayMaxs(vector<int>& nums, vector<long long>& maxVals)
    {
        int N = nums.size();
        
        vector<int> left(N);    // to hold the next larger element on the left
        vector<int> right(N);   // to hold the next larger element on the right
        
        // Left
        stack<int> s;   // Monotonic Stack --> store the latest largest
        for (int i=0; i<N; i++)
        {
            while (!s.empty() && nums[i] > nums[s.top()])   // ***mind ">" for left***
                s.pop();
            
            if (!s.empty())
                left[i] = i - s.top();
            else
                left[i] = i+1;
            
            s.push(i);
        }
       
        // Optimization: Here we can possibly clear the old stack and re-use it.
        // We can also write this for clearing the stack.
        // st=stack<int>();
        
        // Right
        stack<int> st;   // Monotonic Stack --> store the latest largest
        for (int i=N-1; i>=0; i--)
        {
            while (!st.empty() && nums[i] >= nums[st.top()])   // ***mind ">=" for right***
                st.pop();
            
            if (!st.empty())
                right[i] = st.top() - i;
            else
                right[i] = N-i;
            
            st.push(i);
        }
        
        for (int i=0; i<N; i++)
            maxVals[i] = (left[i] * right[i]);
    }
};
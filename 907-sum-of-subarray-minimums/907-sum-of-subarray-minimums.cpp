class Solution
{
    public:
    int mod = pow(10, 9) + 7;
    
    int sumSubarrayMins(vector<int>& nums)
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
        
        int res = 0;
        for (int i=0; i<N; i++)
        {
            long long product = (left[i] * right[i]) % mod;
            product = (product * nums[i]) % mod;
            res = (res + product) % mod;
        }
        return res%mod;
    }
};
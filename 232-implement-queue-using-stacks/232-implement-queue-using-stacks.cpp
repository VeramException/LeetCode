class MyQueue
{
    stack<int> s1;
    stack<int> s2;
    
    public:
    MyQueue()
    {        
    }
    
    void push(int x)
    {
        while (!s1.empty())
            s2.push(pop());

        s2.push(x);
        
        while (!s2.empty())
        {
            int data = s2.top();
            s1.push(data);
            s2.pop();
        }
    }
    
    int pop()
    {
        int top = s1.top();
        s1.pop();
        return top;
    }
    
    int peek()
    {
        return s1.top();
    }
    
    bool empty()
    {
        return s1.empty();
    }
};
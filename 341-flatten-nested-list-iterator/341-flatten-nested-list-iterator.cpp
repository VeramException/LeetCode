class NestedIterator
{
    public:
    stack<NestedInteger*> s;
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (int i=nestedList.size()-1; i>=0; i--)
            s.push(&nestedList[i]);
    }
    
    int next()
    {
        int val = s.top()->getInteger();
        s.pop();
        return val;
    }
    
    bool hasNext()
    {
        while (!s.empty())
        {
            NestedInteger* itr = s.top();
            
            if (itr->isInteger())
                return true;
            
            vector<NestedInteger>& currList = itr->getList();
            s.pop();
            
            for (int i=currList.size()-1; i>=0; i--)
                s.push(&currList[i]);
        }
        return false;
    }
};

class FirstUnique
{
    private:
    list<int> uniqueList;
    unordered_map<int, list<int>::iterator> addressMap;
    
    public:
    FirstUnique(vector<int>& nums)
    {
        for (int num: nums)
            add(num);
    }
    
    int showFirstUnique()
    {
        return uniqueList.empty()? -1: uniqueList.front();
    }
    
    void add(int num)
    {
        auto it = addressMap.find(num);
        
        if (it == addressMap.end())
        {
            uniqueList.push_back(num);
            addressMap[num] = --uniqueList.end();
        }
        else if (it->second != uniqueList.end())
        {
            uniqueList.erase(it->second);
            addressMap[num] = uniqueList.end();
        }
    }
};
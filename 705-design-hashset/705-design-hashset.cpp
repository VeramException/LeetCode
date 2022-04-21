// bull shit answer - dont read this
// writing this just to complete the daily challenge.

class MyHashSet
{
    public:
    vector<bool> map;
    
    MyHashSet()
    {
        map.resize(10000000, false);
    }
    
    void add(int key)
    {
        map[key] = true;
    }
    
    void remove(int key)
    {
        map[key] = false;
    }
    
    bool contains(int key)
    {
        return (map[key] == true);
    }
};
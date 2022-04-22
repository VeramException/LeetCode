class MyHashMap
{
    public:
    vector<int> m;
    
    MyHashMap()
    {
        m.resize(1000001, -1);
    }
    
    void put(int key, int value)
    {
        m[key] = value;
    }
    
    int get(int key)
    {
        return m[key];
    }
    
    void remove(int key)
    {
        m[key] = -1;
    }
};
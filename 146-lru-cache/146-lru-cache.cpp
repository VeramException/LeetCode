class LRUCache
{
    public:
    
    int cache_size;
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    
    LRUCache(int capacity)
    {
        cache_size = capacity;
    }
    
    int get(int key)
    {
        if (m.count(key) > 0)
        {
            li.splice(li.begin(), li, m[key]);  // Take "m[key]" from "li" and place it in the beginning of li.
            return m[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        // Bring it to front, update the key
        if (get(key) != -1)
        {
            m[key]->second = value;
        }
        // New key
        else
        {
            if (m.size() == cache_size)
            {
                int deleteKey = li.back().first;
                li.pop_back();
                m.erase(deleteKey);
            }
            
            li.push_front({key, value});
            m[key] = li.begin();
        }
    }
};





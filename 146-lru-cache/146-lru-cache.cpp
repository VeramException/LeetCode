struct Node
{
    int key, val;
    Node* prev;
    Node* next;
    Node (int x, int y): key(x), val(y), prev(nullptr), next(nullptr) { }
};

class LRUCache
{
    public:
    
    int cache_size;
    unordered_map<int, Node*> m;
    
    Node* first; // least used
    Node* last;  // recently used
    
    LRUCache(int capacity)
    {
        first = nullptr;
        last = nullptr;
        cache_size = capacity;
    }
    
    int get(int key)
    {
        if (m.count(key) > 0)
        {
            put(key, m[key]->val); // Touch the key so that it is brought back to the first.
            return m[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        // key exists
        if (m.count(key) > 0)
        {
            m[key]->val = value;
            Node* node = m[key];
            
            // First Node
            if (node == last)
            {
            }
            else if (node == first)
            {
                // remove this node from first
                first = first->next;
                first->prev = nullptr;
                
                // add this node at the last
                pushNodeToEnd(node);
            }
            else
            {
                // connect previous and next nodes.
                node->prev->next = node->next;
                node->next->prev = node->prev;
                
                // add this node at the last
                pushNodeToEnd(node);
            }
        }
        // new key
        else
        {
            Node* node = new Node(key, value);
            m[key] = node;
            
            if (first == nullptr)
            {
                first = node;
                last = node;
            }
            else
            {
                // add this node at the last
                pushNodeToEnd(node);
                
                if (m.size() > cache_size)
                {
                    // remove first node
                    m.erase(m.find(first->key));
                    
                    Node* toDelete = first;
                    first = first->next;
                    first->prev = nullptr;
                    
                    delete(toDelete);
                }
            }
        }
    }
    
    void pushNodeToEnd(Node* node)
    {
        last->next = node;
        node->prev = last;
        node->next = nullptr;
        last = node;
    }
};





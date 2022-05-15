#define MAX_CHARS 128


class Trie 
{
    public:
    
    // members
    Trie* children[MAX_CHARS];
    bool isLeaf;
    
    // methods
    /** Initialize your data structure here. */
    Trie() 
    {
        for(int i=0; i<MAX_CHARS; i++)
            this->children[i] = nullptr;

        isLeaf = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Trie* curr = this;
        for(char c : word)
        {
            if (curr->children[c] == nullptr)
                curr->children[c] = new Trie();
            curr = curr->children[c];
        }
        curr->isLeaf = true;
    }
    
    Trie* findLastNode(string word)
    {
        if (this == nullptr)
            return nullptr;
        
        Trie* curr = this;
        for(char c : word)
        {
            // go to the next node
            curr = curr->children[c];
            
            if(curr == nullptr)
                return nullptr;
        }
        return curr;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Trie* lastNode = findLastNode(word);        
        return (lastNode!=nullptr)? lastNode->isLeaf: false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        Trie* lastNode = findLastNode(prefix);
        return (lastNode!=nullptr)? true: false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
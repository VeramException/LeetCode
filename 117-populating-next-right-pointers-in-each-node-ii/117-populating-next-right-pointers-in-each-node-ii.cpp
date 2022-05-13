class Solution
{
    public:
    Node* connect(Node* root)
    {
        Node* current = root;
        Node* dummy = new Node(0);
        
        while (current)
        {
            for(Node* prev = dummy; current!=nullptr; current=current->next)
            {
                if (current->left)
                {
                    prev->next = current->left;
                    prev = prev->next;
                }
                
                if (current->right)
                {
                    prev->next = current->right;
                    prev = prev->next;
                }
            }
            current = dummy->next;
            dummy->next = nullptr;
        }
        
        return root;
    }
};
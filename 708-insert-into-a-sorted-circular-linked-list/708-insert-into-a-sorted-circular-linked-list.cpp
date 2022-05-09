class Solution
{
    public:
    Node* insert(Node* head, int insertVal)
    {
        Node* newNode = new Node(insertVal);
        newNode->next = newNode;
        
        if (head == nullptr)
            return newNode;
        
        Node* prev = head;
        Node* curr = head->next;
        
        while (curr != head)
        {
            if (prev->val <= insertVal && insertVal <= curr->val)
                break;
            else if (prev->val > curr->val && (prev->val < insertVal || insertVal < curr->val))
                break;
            
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = newNode;
        newNode->next = curr;
        
        return head;
    }
};
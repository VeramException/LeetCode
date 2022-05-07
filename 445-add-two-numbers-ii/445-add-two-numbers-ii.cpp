class Solution
{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        string a = getNumber(l1);
        string b = getNumber(l2);
        return sum(a, b);
    }
    
    string getNumber(ListNode* node)
    {
        string res = "";
        while (node != nullptr)
        {
            res += to_string(node->val);
            node = node->next;
        }
        return res;
    }
    
    ListNode* sum(string a, string b)
    {        
        int carry = 0;
        int i = a.size()-1, j = b.size()-1;
        ListNode* head = nullptr;
        while (i >= 0 || j >= 0)
        {
            int currSum = carry;
            
            if (i >= 0) currSum += (a[i] - '0');
            if (j >= 0) currSum += (b[j] - '0');
            
            carry   = currSum/10;
            currSum = currSum%10;
            
            ListNode* node = new ListNode(currSum);
            node->next = head;
            head = node;
            
            i--, j--;
        }
        
        if (carry != 0)
        {
            ListNode* node = new ListNode(carry);
            node->next = head;
            head = node;
        }        
        return head;
    }
};
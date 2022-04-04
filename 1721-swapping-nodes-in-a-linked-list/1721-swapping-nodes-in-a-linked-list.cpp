/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode* l = head;
        int x = k;
        while (l != nullptr && x > 1)
        {
            l = l->next;
            x--;
        }
        
        ListNode* r1 = head;
        ListNode* r2 = l;
        while (r2->next != nullptr)
        {
            r1 = r1->next;
            r2 = r2->next;
        }
        
        swap(l->val, r1->val);
        return head;
    }
};
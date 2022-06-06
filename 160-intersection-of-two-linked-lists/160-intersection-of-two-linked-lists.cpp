/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int length_A = 0;
        ListNode* temp = headA;
        while (temp != nullptr)
        {
            length_A++;
            temp = temp->next;
        }
        
        int length_B = 0;
        temp = headB;
        while (temp != nullptr)
        {
            length_B++;
            temp = temp->next;
        }
        
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while (t1 != nullptr && length_A > length_B)
        {
            t1 = t1->next;
            length_A--;                
        }
        while (t2 != nullptr && length_B > length_A)
        {
            t2 = t2->next;
            length_B--;                
        }
        
        while (t1 && t2 && t1 != t2)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
};

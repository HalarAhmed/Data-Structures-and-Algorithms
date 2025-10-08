/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
							// Slow and fast pointer approach:
class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL)   // Until slow and fast pointers coincide, the loop keeps running!
        {
            slow=slow->next;	// moves 1 step at a time.
            fast=fast->next->next;	// moves 2 steps at a time.
            if(slow==fast)	// both the pointers are bound to coincide as the net distance reduction is always going to 1.
            {
                return true;
            }
        }
        return false;
    }
};

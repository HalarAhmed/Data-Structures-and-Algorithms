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
				    // Brute Force Approach:
class Solution 
{
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *temp=head;
        int size=0;
        while(temp!=NULL) // Here in this loop we first calculate the size of LinkedList.
        {
            size++;
            temp=temp->next;
        }
        int midNode=(size/2)+1;
        temp=head;
        for(int i=0;i<midNode;i++) // After finding the middle node we move to finding it through traversing the whole likedlist.
        {
            if(i==midNode-1)
            {
                return temp;
            }
            temp=temp->next;	// Updating to traverse forward
        }
        return temp;
    }
};
							// Slow and fast pointer approach:
class Solution 
{
public:
    // Slow fast pointer approach:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;	// Moving slow pointer 1 step at a time.
            fast=fast->next->next;	// Moving fast pointer 2 steps at a time.
        }
        return slow; // the slow pointer automatically just points to the middle of 'LL' when the the fast pointer reaches the NULL or just before NULL.
    }
};

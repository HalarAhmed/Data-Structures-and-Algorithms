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
    ListNode* reverseList(ListNode* head) 
    {
    	// For handling edge cases where the code might fail on 'runtime' due to a NULL pointer like an empty LL or LL with only one element
        if(head == NULL || head->next == NULL) 
        {
            return head;
        }
        else
        {
            ListNode *temp=head; // for saving the address of the nodes forward.
            ListNode *prevNode=head;// for the first node
            ListNode* curNode=head->next;// for the second node
            while(curNode!=NULL)
            {
                temp->next=curNode->next;// for saving the address of the nodes forward.
                curNode->next=prevNode;// for building a connection backward.
                prevNode=curNode;// for moving forward.
                curNode=temp->next;// using the address we saved for moving forward
            }
            return prevNode;
        }
    }
};

/* So in short, the approach consists of 3 pointers and 4 steps.
   We just break the forward connection and point the next pointer towards the previous node
*/



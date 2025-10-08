using namespace std;
#include<iostream>
// Node:
class Node
{
public:
	int data;
	Node *next;
	// Constructor:
	Node(int val)
	{
		data=val;
		next=NULL;
	}
};
class CircularList
{
	Node *head;
	Node *tail;
public:
	// Circular linked list:
	CircularList()
	{
		head=tail=NULL;
	}
	// Function for inserting a node at head:
	void insertAtHead(int val)		// TC=O(1), SC=O(1)
	{
		if(head==NULL)
		{
			Node *newNode=new Node(val);
			head=tail=newNode;
		}
		else
		{
			Node *newNode=new Node(val);
			newNode->next=head;		// newNode->next=tail->next
			head=newNode;			// tail->next=newNode
			tail->next=head;		// tail->next=tail
		}
	}
	// function for inserting at tail:
	void insertAtTail(int val)		// TC=O(1), SC=O(1)
	{
		if(tail==NULL)	// if linked list is empty.
		{
			Node *newNode=new Node(val);
			head=tail=newNode;
			newNode->next=tail;
		}
		else
		{
			Node *newNode=new Node(val);
			tail->next=newNode;
			tail=newNode;
			tail->next=head;
		}
	}
	// function for deleting a node from head:
	void deleteAtHead()		// TC=O(1), SC=O(1) 
	{
		if(head==NULL)
		{
			return;
		}
		else if(head==tail)
		{
			delete head;
			head=tail=NULL;
			return;
		}
		else
		{
			Node *temp;
			temp=head->next;	// storing the address of the next node as the head is going to get deleted.
			head->next=NULL;	// for dangling pointers.
			delete head;	// deleting head from heap.
			head=temp;	// assigning new head.
			tail->next=head;	// finally linking the tail after updating the head.
		}
	}
	// function for deleting a node from tail:
	void deleteAtTail()		// TC=O(n), SC=O(1)
	{
		if(tail==NULL)	// empty LL
		{
			return;
		}
		else if(head==tail)		// LL with single node.
		{
			delete tail;
			head=tail=NULL;
		}
		else
		{
			Node *temp=head;
			while(true)	// traversing the LL until we reach the second last node of LL.
			{
				if(temp->next==tail)
				{
					delete tail;	// deleting tail in heap.
					tail=temp;	// pointing the tail to the address of the second last node.
					tail->next=head;// finally pointing the tail to the head.
					return;
				}
				else
				{
					temp=temp->next;
				}
			}
		}
	}
	// print():
	void print()	// TC=O(n), SC=O(1)
	{
		if(head==NULL)	
		{
			return;
		}
		else
		{
			cout<<head->data<<"->";
			Node *temp=head->next;
			while(temp!=head)
			{
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<temp->data<<endl;
		}
	}
};
int main()
{
	CircularList cll;
	cll.insertAtHead(1);
	cll.insertAtHead(2);
	cll.insertAtHead(3);
	cll.insertAtHead(4);
	cll.insertAtHead(5);
	cll.insertAtTail(6);
	cll.insertAtTail(7);
	cll.print();
}

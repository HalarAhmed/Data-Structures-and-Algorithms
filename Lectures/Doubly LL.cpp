using namespace std;
#include<iostream>
// Node:
class Node
{
public:
	int data;
	Node *prev;	// pointer for previous node.
	Node *next;	// pointer for next node.
	// Constructor for saving a value at each node.
	Node(int val)
	{
		data=val;
		next=prev=NULL;
	}
};
class DoublyLL
{
	Node *head;
	Node *tail;
public:
	// Constructor to initialise head and tail as NULL.
	DoublyLL()
	{
		head=tail=NULL;
	}
	// push_front():
	void push_front(int val)	// TC=O(1), SC=O(1)
	{
		Node *newNode=new Node(val);
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
			newNode->next=head; // (*newNode.next=head)
			head->prev=newNode;
			head=newNode;
		}
	}
	// print(): to print the doubly LL.
	void print()	// TC=O(n), SC=O(1)
	{
		Node *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"<=>";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
	}
	// push_back():
	void push_back(int val)		// TC=O(1), SC=O(1)
	{
		Node *newNode=new Node(val);
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
			tail->next=newNode;
			newNode->prev=tail;
			tail=newNode;
		}
	}
	// pop_front:
	void pop_front()	// TC=O(1), SC=O(1)
	{
		Node *temp=head;
		head=head->next;
		if(head==NULL)
		{
			return;
		}
		if(head!=NULL)
		{
			head->prev=NULL;
		}
		temp->next=NULL;	// Not necessary but it is a good practice(dangling pointers).
		delete temp;
	}
	// pop_back():
	void pop_back()		// TC=O(1), SC=O(1)
	{
		Node *temp=tail;
		tail=tail->prev;
		if(tail==NULL)
		{
			return;
		}
		if(tail!=NULL)
		{
			tail->next=NULL;
		}
		temp->prev=NULL;
		delete temp;
	}
	// insert(): 
	void insert(int val,int pos)
	{
			if(head==NULL)
			{
				push_front(val);
			}
			else
			{
				int size=0;
				Node *temp=head;
				int idx=0;
				while(temp!=NULL)	// Time Complexity=O(n)
				{
					size++;
					temp=temp->next;
				}
				while(temp!=NULL && pos<size)	// Time Complexity=O(n-1)
				{
					if(pos-1==idx+1)	// this condition is written here to stop our traversal one node before the actual position.
					{
						Node *newNode=new Node(val);
						Node *del=temp->next;	// saving the address of (pos+1) ptr.
						temp->next=newNode;
						newNode->prev=temp;
						newNode->next=del;
						del->prev=newNode;	// (temp->next->prev) pointing the prev pointer of (pos+1) to new node.
						return;
					}
					else
					{
						idx++;
						temp=temp->next;	// moving forward!
					}
				}
				if(pos==size)	// O(1)
				{
					push_back(val);
				}
			}
	}
};
int main()
{
	DoublyLL dll;
	dll.push_front(3);
	dll.push_front(2);
	dll.push_front(1);
	dll.print();
	dll.pop_front();
	dll.push_front(1);
	dll.print();
	dll.insert(12,3);
	dll.print();
}

using namespace std;
#include<iostream>
class Node
{
public:
	int data;	// for storing the value of any node.
	Node *next;	// for pointing towards the next node.
	// Constructor:
	Node(int val)
	{
		data=val;
		next=NULL;// initially pointed towards NULL.
	}
};
class List
{
	Node *head;// pointer for the first node of the linked list.
	Node *tail;// pointer for the last node of the linked list.
public:
	List()
	{
		head=tail=NULL;// intially we point towards NULL as the linkedlist is empty.
	}
	// push_front: function to push any value at the start of the linkedlist.
	void push_front(int val)
	{
		// Creating a new node
		Node *newNode=new Node(val);// creating it dynamically so that it doesn't get destroyed after the function call.
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
			newNode->next=head;
			head=newNode;
		}
	}
	// push_back = Function to push a value at the end of the linkedlist.
	void push_back(int val)
	{
		Node *newNode=new Node(val);
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
			tail->next=newNode;
			tail=newNode;
		}
	}
	// pop_front(): function to pop a value from the start of the linkedlist.
	void pop_front()
	{
		if(head==NULL)
		{
			cout<<"Linkedlist is empty!"<<endl;
		}
		else
		{
			Node *temp=head;
			temp->next=NULL;
			head=head->next;
			delete temp;
		}
	}
	// pop_back: Function to remove a value from the last of the linkedlist.
	void pop_back()
	{
		if(head==NULL)
		{
			cout<<"Linkedlist is empty!"<<endl;
			return;
		}
		else
		{
			Node *temp=head;
			while(temp->next!=tail)
			{
				temp=temp->next;
			}
			temp->next=NULL;
			delete tail; // delete keyword deletes the memory/data inside the heap memory of the tail variable not the variable itself!
			tail=temp; // bcz tail itself is stored inside stack memory but it points to heap memory as the every node is created dynamically.
		}
	}
	// insert(): inserts in between anywhere of a linkedlist.
	void insert(int val,int pos)
	{
		if(pos<0)
		{
			cout<<"Invalid position!"<<endl;
			return;
		}
		if(pos==0)
		{
			push_front(val);
			return;
		}
		Node *temp=head;
		for(int i=0;i<pos-1;i++)
		{
			if(temp==NULL)
			{
				cout<<"Invalid position"<<endl;
				return;
			}
			temp=temp->next;
		}
		Node *newNode=new Node(val);
		newNode->next=temp->next;
		temp->next=newNode;
	}
	// search(): function to search a value:
	int search(int key)
	{
		Node *temp=head;
		int idx=0;
		while(temp!=NULL)
		{
			if(temp->data==key)
			{
				return idx;
			}
			temp=temp->next;
			idx++;
		}
	}
	// Function: Printing a linked list
	void print()
	{
		Node *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
};
int main()
{
	List ll;
	ll.push_front(1);
	ll.push_front(2);
	ll.push_front(3);
	ll.insert(4,2);
	ll.print();
	cout<<endl;
	List ll1;
	ll1.push_back(1);
	ll1.push_back(2);
	ll1.push_back(3);
	ll1.print();
	cout<<endl;
	cout<<ll.search(4)<<endl;
}

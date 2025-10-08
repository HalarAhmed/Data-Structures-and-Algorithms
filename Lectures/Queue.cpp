using namespace std;
#include<iostream>
class Node 
{
public:
	int data;
	Node *next;
	Node(int val)
	{
		data=val;
		next=NULL;
	}
};

class Queue
{
	Node *head;
	Node *tail;
public:
	void push(int val)
	{
		Node *newNode=new Node(val);
		if(empty())
		{
			head=tail=newNode;
		}
		else
		{
			tail->next=newNode;
			tail=newNode;
		}
	}
	void pop()
	{
		if(empty())
		{
			return;
		}
		else
		{
			Node *temp=head->next;
			delete head;
			head=temp;
		}
	}
	int front()
	{
		if(empty())
		{
			return -1;
		}
		else
		{
			return head->data;
		}
	}
	bool empty()
	{
		return head==NULL;
	}
//	void print()
//	{
//		Node *temp=head;
//		while(temp!=NULL)
//		{
//			cout<<temp->data<<" ";
//		}
//		temp=temp->next;
//	}
};
int main()
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<q.empty()<<endl;
}

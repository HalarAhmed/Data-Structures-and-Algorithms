using namespace std;
#include<iostream>
#include<list>
class Stack
{
	list<int>ll;
public:
	void push(int val)
	{
		ll.push_front(val);
	}
	int top()
	{
		return ll.front();
	}
	void pop()
	{
		ll.pop_front();
	}
	bool empty()
	{
		return ll.size()==0; 
	}
};
int main()
{
	
}

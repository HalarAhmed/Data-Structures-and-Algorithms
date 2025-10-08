using namespace std;
#include<iostream>
#include<vector>
class Stack
{
	vector<int>v;
public:
	// Push back in a stack:
	void push_back(int val)	// TC=O(1)
	{
		v.push_back(val);
	}
	// pop back in a stack:
	void pop_back()
	{
		v.pop_back();
	}
	// returning the top:
	int top()
	{
		return v[v.size()-1];
	}
	// checking if the stack is empty:
	bool empty()
	{
		if(v.size()==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
int main()
{
	Stack S;
	S.push_back(1);
	S.push_back(2);
	S.push_back(3);
	S.push_back(4);
	S.push_back(5);
	// Printing the values:
	while(!S.empty())
	{
		cout<<S.top()<<" ";
		S.pop_back();
	}
}

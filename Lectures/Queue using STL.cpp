using namespace std;
#include<iostream>
#include<queue>
#include<deque>
int main()
{
	queue<int>q;
	q.push(1);
	q.push(2);
	q.push(3);
	deque<int>dq;
	dq.push_front(2);
	dq.push_back(3);
	cout<<"Front: "<<dq.front()<<endl;
	cout<<"Back:"<<dq.back()<<endl;
}

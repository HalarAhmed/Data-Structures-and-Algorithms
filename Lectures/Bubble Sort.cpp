/* Approach:
	the greatest element shifts to the last index in the first iteration than the 
	element just smaller than that shifts on second last index and so on.
*/
using namespace std;
#include<bits/stdc++.h>
int main()
{
	vector<int>v;
	int n;
	int el;
	cin>>n;
	// filling the array:
	for(int i=0;i<n;i++)
	{
		cin>>el;
		v.push_back(el);
	}
	int temp;
	// Sorting starts here:
	for(int i=0;i<n-1;i++)	// Outer loop
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(v[j]>v[j+1])	// comparing each element and if it's greater than the element next to it they are swapped.
			{
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
	// Printing the elements one by one.
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}

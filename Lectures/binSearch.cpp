using namespace std;
#include<iostream>
#include<vector>
int binSearch(vector<int>arr,int tar)	// Iterative Approach
{
	int mid,st=0,end=arr.size()-1;
	while(st<=end)
	{
		mid=st+(end-st)/2;
		if(tar>arr[mid])
		{
			st=mid+1;
		}
		else if(tar<arr[mid])
		{
			end=mid-1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int BS(vector<int>arr,int tar,int st,int end)	// Recursive Approach
{
	int mid=st+(end-st)/2;
	if(st<=end)
	{
		if(tar>arr[mid])	// Searching in 2nd half
		{
			return BS(arr,tar,mid+1,end);
		}
		else if(tar<arr[mid])	// Searching in 1st half
		{
			return BS(arr,tar,st,mid-1);
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	vector<int>arr1={2,3,4,5,6};	// odd sized
	vector<int>arr2={2,3,4,5,6,7};  // even sized
	int tar=5;
	cout<<"Index: "<<binSearch(arr1,tar)<<endl;
	cout<<"Index: "<<binSearch(arr2,tar)<<endl;
	cout<<"Index: "<<BS(arr1,0,0,arr1.size()-1)<<endl;
}

using namespace std;
#include<bits/stdc++.h>
void merge(vector<int>&arr,int st,int mid,int end)
{
	vector<int>temp;
	int left=st;
	int right=mid+1;
	while(left<=mid && right<=end)
	{
		if(arr[left]<=arr[right])
		{
			temp.push_back(arr[left]);
			++left;
		}
		else
		{
			temp.push_back(arr[right]);
			++right;
		}
	}
	while(left<=mid)
	{
		temp.push_back(arr[left]);
		++left;
	}
	while(right<=end)
	{
		temp.push_back(arr[right]);
		++right;
	}
	for(int i=st;i<=end;i++)
	{
		arr[i]=temp[i-st];
	}
}
void mergeSort(vector<int>&arr,int st,int end)
{
	if(st>=end)
	{
		return;
	}
	int mid=st+(end-st)/2;
	mergeSort(arr,st,mid);
	mergeSort(arr,mid+1,end);
	merge(arr,st,mid,end);
}
void print(vector<int>&arr)
{
	for(int i=0;i<arr.size();++i)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	vector<int>arr={3,2,4,3,1};
	mergeSort(arr,0,4);
	print(arr);
}

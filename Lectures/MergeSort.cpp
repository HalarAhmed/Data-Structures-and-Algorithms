using namespace std;
#include<bits/stdc++.h>
void merge(vector<int>&arr,int st,int mid,int end)
{
	vector<int>temp;
	int i=st;
	int j=mid+1;
	// sorting the elements and then storing them into a temporary array:
	while(i<=mid && j<=end)
	{
		if(arr[i]<=arr[j])
		{
			temp.push_back(arr[i]);
			i++;
		}
		else
		{
			temp.push_back(arr[j]);
			j++;
		}
	}
	// inserting the remaining elements
	while(i<=mid)
	{
		temp.push_back(arr[i]);
		i++;
	}
	while(j<=end)
	{
		temp.push_back(arr[j]);
		j++;
	}
	// inserting the elements into the array:
	for(int i=0;i<temp.size();i++)
	{
		arr[i+st]=temp[i];
	}
}
void mergeSort(vector<int>&arr,int st,int end)
{
	if(st<end)
	{
		int mid=st+(end-st)/2;	// mid
		
		mergeSort(arr,st,mid);	// left half
		mergeSort(arr,mid+1,end);	// right half
		
		// merging the array by backtracking:
		merge(arr,st,mid,end);
	}
}
int main()
{
	
}

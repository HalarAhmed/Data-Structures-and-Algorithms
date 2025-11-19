using namespace std;
#include<bits/stdc++.h>
int partition(int A[],int l,int h)
{
	int pivot=A[l];
	int i=l;
	int j=h;
	while(i<j)
	{
		do
		{
			i++;
		}
		while(A[i]<=pivot);
		do
		{
			j--;
		}
		while(A[j]>pivot);
		if(i<j)
		{
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}	
	}
	int temp=A[l];
	A[l]=A[j];
	A[j]=temp;
	return j;
}
void QuickSort(int A[],int l,int h)
{
	int j;
	if(l<h)
	{
		j=partition(A,l,h);
		QuickSort(A,l,j);
		QuickSort(A,j+1,h);
	}
}
int main()
{
	int arr[10]={10,16,8,12,15,6,3,9,5,INT_MAX};
	QuickSort(arr,0,9);
	cout<<"_______Sorted Array_______"<<endl;
	for(int i=0;i<9;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}

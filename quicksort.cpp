#include<iostream>
using namespace std;
int partition(int arr[],int l,int h)
{
	int pivot=arr[l];
	int i=l,j=h;
	while(i<j)
	{
		while(arr[i]<=pivot)
		i++;
		while(arr[j]>=pivot)
		j--;	
		if(i<j)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	arr[l]=arr[j];
	arr[j]=pivot;
	return j;
}
void quick_sort(int arr[],int l,int h)
{
	if(l<h)
	{
		int loc=partition(arr,l,h);
		quick_sort(arr,l,loc-1);
		quick_sort(arr,loc+1,h);
	}
}
int main()
{
	int arr[7],i,c=0;
	cout<<"Enter element of array ";
	for(i=0;i<7;i++)
	cin>>arr[i];	
	quick_sort(arr,0,6);
	cout<<"Element of list after sorting "<<endl;
	for(i=0;i<7;i++)
	cout<<arr[i]<<"\t";
}

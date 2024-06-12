#include<stdio.h>
int count=0;
void merge(int arr[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=low,temp[50];
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
			temp[k]=arr[i];
			i++;
			k++;
		}
		else
		{
			temp[k]=arr[j];
			j++;
			k++;
		    count++;
		}
    }
		if(i>mid)
		{
			while(j<=high)
			{
				temp[k]=arr[j];
				j++;
				k++;
			}
		}
		else if(i<=mid)
		{
			while(i<=mid)
			{
				temp[k]=arr[i];
				i++;
				k++;
			}
		}
	for(i=low;i<=high;i++)
	{
		arr[i]=temp[i];
	}
}
void merge_sort(int arr[],int low,int high )
{
	if(low<high)
	{
		int mid=(low+high)/2;
		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
int main()
{
	int arr[10],n,i;
	printf("enter the size of list=");
	scanf("%d",&n);
	printf("enter the %d elements",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,0,n-1);
	printf(" sorting list\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\n",arr[i]);
	}
	printf("the comparisons=%d",count);
}

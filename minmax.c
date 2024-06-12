#include<stdio.h>
int min,max;
int a[100];
void maxmin(int i,int j)
{
	int max1,min1,mid;
	if(i==j)
	{
		max=min=a[i];
	}
	else
	{
		if(i==j-1)
		{
			if(a[i]<a[j])
			{
				max=a[i];
				min=a[j];
			}
			else
			{
				max=a[i];
				min=a[j];
			}
		}
	else
	{
		mid=(i+j)/2;
		maxmin(i,mid);
		max1=max;
		min1=min;
		maxmin(mid+1,j);
		if(max<max1)
		{
		 	max=max1;
		}
		if(min>min1)
		{
			min=min1;
		}
	}
  }
}
int main()
{
	int i,j,size;
	printf("\n enter the size of element=");
	scanf("%d",&size);
	printf("enter the elements=\n");
	for(i=1;i<=size;i++)
	{
		scanf("%d",&a[i]);
	}
	i=0,j=size-1;
	maxmin(i,j);
	printf("minimum element in an array =%d\n",min);
	printf("maximum element in an array=%d\n",max);
	return 0;
}

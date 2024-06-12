#include<stdio.h>
int main()
{
	int profit=0;
	int count=0;
	int dmax=0;
	int slot[5];
	int jobNo[5];
	int job[5]={1,2,3,4,5};
	int p[5],d[5];
	int i,j,r,temp=0;
	
	printf("enter the profit and deadline of each job\n");
	for(i=0;i<5;i++)
	{
		printf("profit:");
		scanf("%d",&p[i]);
	}
	for(i=0;i<5;i++)
	{
		printf("deadline:");
		scanf("%d",&d[i]);
	}
	for( i=0;i<5;i++)
	{
		for( j=i+1;j<5;j++)
		{
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
			
			temp=d[i];
			d[i]=d[j];
			d[j]=temp;
			
			temp=job[i];
			job[i]=job[j];
			job[j]=temp;
		}
for(i=0;i<5;i++)
		{
			if(d[i]>dmax)
			{
				dmax=d[i];
			}
		}
		for(i=0;i<=dmax;i++)
		{
			slot[i]=-1;
		}
		for(i=0;i<5;i++)
		{
			for(r=d[i];i>=0;i--)
			{
				if(slot[r]==-1)
				{
					profit+=p[i];
					jobNo[i]=job[i];
					count++;
					break;
				}
			}
			if(count==dmax)
			{
				break;
			}
		}
	}
	printf("Profit=%d",profit);
	for(i=0;i<dmax;i++)
	{
		printf("\nJob no is %d",jobNo[i]);
	}
}

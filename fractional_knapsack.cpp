#include<iostream>
using namespace std;
int main()
{
	int n,i,j;
	cout<<"Enter number of objects "<<endl;
	cin>>n;
	
	float profit[n],weight[n],ratio[n],total_profit=0,capacity,temp;
	for(i=0;i<n;i++)
	{
		cout<<"Enter profit and weight "<<i+1<<"object "<<endl;
		cin>>profit[i]>>weight[i];
		ratio[i]=profit[i]/weight[i];
	}
	cout<<"Enter capacity ";
	cin>>capacity;
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ratio[i]<ratio[j])
			{
				temp=ratio[i];
				ratio[i]=ratio[j];
				ratio[j]=temp;
				
				temp=weight[i];
				weight[i]=weight[j];
				weight[j]=temp;
				
				temp=profit[i];
				profit[i]=profit[j];
				profit[j]=temp;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(weight[i]>capacity)
			break;
			
		total_profit+=profit[i];;
		capacity-=weight[i];
	}
	if(i<n)
	{
		total_profit+=(profit[i]*(capacity/weight[i]));
	}
	cout<<"Total profit is "<<total_profit<<endl;
}

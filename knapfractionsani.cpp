#include<iostream>
using namespace std;
int main()
{
	int size;
	cout<<"enter the size of array"<<endl;
	cin>>size;
	float profit[size],weight[size];
	int i;
	cout<<"enter the profit of array"<<endl;
	for(i=0;i<size;i++)
	{
		cin>>profit[i];
	}
	cout<<"enter the weight of array"<<endl;
	int j;
	for(j=0;j<size;j++)
	{
		cin>>weight[j];
	}
	float ratio[size];
	int k;
	for(k=0;k<size;k++)
	{
		ratio[k]=profit[k]/weight[k];
		cout<<ratio[k]<<endl;
	}
	cout<<"sorting is :"<<endl;
	float temp;
	int p,q,v,s;
	for(p=0;p<size;p++)
	{
		for(q=0;q<size;q++)
		{
			if(ratio[q]<ratio[q+1])
			{
				temp=ratio[q];
				ratio[q]=ratio[q+1];
				ratio[q+1]=temp;
				
				v=profit[q];
				profit[q]=profit[q+1];
				profit[q+1]=v;
				
				s=weight[q];
				weight[q]=weight[q+1];
				weight[q+1]=s;
			}
		}
	}
	int h;
	for(h=0;h<size;h++)
	{
		cout<<ratio[h]<<"\t";
	}
	cout<<"profit"<<endl;
	for(h=0;h<size;h++)
	{
		cout<<profit[h]<<"\t";
	}
		cout<<"weight"<<endl;
	for(h=0;h<size;h++)
	{
		cout<<weight[h]<<"\t";
	}
	cout<<endl;
	int knapweight;
	cout<<"enter the knapsack weight"<<endl;
	cin>>knapweight;
	float pro=0;
	for(h=0;h<size;h++)
	{
		if(knapweight>0&&weight[h]<=knapweight)
		{
		knapweight=knapweight-weight[h];
		pro=pro+profit[h];
		}
		else
		{
			break;
		}
	}
	cout<<"profit is :"<<pro<<endl;
	if(knapweight>0)
	{
		pro=pro+profit[h]*knapweight/weight[h];
	}
	cout<<"profit is :"<<pro<<endl;
}

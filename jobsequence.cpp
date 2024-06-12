#include<iostream>
using namespace std;
int main()
{
	cout<<"enter no of jobs"<<endl;
	int size;
	cin>>size;
	char job[size];
	cout<<"enter jobs "<<endl;
	int i;
	for(i=0;i<size;i++)
	{
		cin>>job[i];
	}
	int profit[size];
	cout<<"enter profit of job"<<endl;
	for(i=0;i<size;i++)
	{
		cin>>profit[i];
	}
	cout<<"enter deadline of job "<<endl;
	int dead[size];
	for(i=0;i<size;i++)
	{
		cin>>dead[i];
	}
	int temp,j,a=0,teob,teline;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-1;j++)
		{
			if(profit[j]<profit[j+1])
			{
				temp=profit[j];
				profit[j]=profit[j+1];
				profit[j+1]=temp;
		
				teob=job[j];
				job[j]=job[j+1];
				job[j+1]=teob;
				
				teline=dead[j];
				dead[j]=dead[j+1];
				dead[j+1]=teline;
			}
		}
	}
	for(i=0;i<size;i++)
	{
		cout<<job[i]<<"\t";
	}
	cout<<endl;
	for(i=0;i<size;i++)
	{
		cout<<profit[i]<<"\t";
	}
	cout<<endl;
	for(i=0;i<size;i++)
	{
		cout<<dead[i]<<"\t";
	}
	int dmax=0;
	for(i=0;i<size;i++)
	{
		if(dmax<=dead[i])
		{
			dmax=dead[i];
		}
	}
	cout<<endl;
	cout<<"max dead line :"<<dmax<<endl;
	char slot[dmax];
	for(i=0;i<dmax;i++)
	{
		slot[i]='0';
	}
	int v=0,pro=0;
	for(i=0;i<dmax;i++)
	{
		v=dead[i];
		v--;
		//cout<<" v :"<<v--<<endl;
		if(v<=dmax)
		{
			if(slot[v]=='0')
			{
				slot[v]=job[i];
				pro=pro+profit[i];
			}
			else
			{
				if(v<=slot[v])
				{
					v=v-1;
					if(slot[v]=='0')
					{
						slot[v]=job[i];
						pro=pro+profit[v];
					}
				}
			}
		}
	}
	cout<<"slot"<<endl;
	for(i=0;i<dmax;i++)
	{
		cout<<slot[i]<<"\t";
	}
	cout<<endl;
	cout<<"profit is :"<<pro<<endl;
}

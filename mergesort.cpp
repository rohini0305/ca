#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int low,int high,int mid)
{
    int i,j,k,temp[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            i++;
        }
        else
        {
            temp[k]=a[j];
            j++;
        }
            k++;
    }
    while(i<=mid) 
	{
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=high) 
	{
        temp[k]=a[j];
        j++;
        k++;
    }
    for(i=low;i<=high;i++) 
	{
        a[i]=temp[i];
    }
}
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
}
int main()
{
    int size;
    cout<<"Enter size:";
    cin>>size;
    int a[size],max,min;
    cout<<"Enter elements:";
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    cout<<"After sorting:";
    mergesort(a,0,size-1);
    for (int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

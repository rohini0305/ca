#include<iostream>
using namespace std;
int Binarysearch(int arr[],int size,int search,int *count)
{   
	int mid;
    int low=0;
    int high=size-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==search)
        {
            (*count)++;
            return mid;
        }
        else if(arr[mid]<search)
        {
            low=mid+1;
            (*count)++;
        }
        else
        {
            high=mid-1;
            (*count)++;
        }
    }
    return 0;
}
int main()
{    
	int size;
    cout<<"Enter the size of an array : ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elemnts of an array : ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int search;
    cout<<"Enter the element to search in array : ";
    cin>>search;
 	int count=0;
    int ans=Binarysearch( arr,size,search,&count);
    if(ans==-1)
    {
        cout<<"Error : Data is not found.";
    }
    else
    {
        cout<<"The data is foud at "<<ans+1<<" index"<<endl;
    }
    cout<<"The total Itertions done for the operation are : "<<count<<endl;
}


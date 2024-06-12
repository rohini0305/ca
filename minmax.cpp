#include <bits/stdc++.h> 
int Count=0; 
using namespace std; 
void max_min(int a[],int i,int j,int &max,int &min) 
{ 
    int mid,max1,min1; 
    if(i==j) 
    { 
        max=min=a[i]; 
    } 
    else if(i==j-1) 
    { 
        if(a[i]<a[j]) 
        { 
            min=a[i]; 
            max=a[j]; 
        } 
        else 
        { 
            min=a[j]; 
            max=a[i]; 
        } 
        Count++; 
    } 
    else 
    { 
        mid=(i+j)/2; 
        max1=max; 
        min1=min; 
        max_min(a,i,mid,max,min); 
        max_min(a,mid+1,j,max1,min1); 
        if(max<max1) 
        { 
            max=max1; 
        } 
        if(min>min1) 
        { 
            min=min1; 
        } 
        Count++; 
    } 
} 
int main() 
{
    int size;
    cout<<"Enter size:";
    cin>>size;
    int a[size],max,min; 
    cout<<"Enter elements:";
    for (int i=0;i<size;i++) 
    { 
        cin>>a[i]; 
    } 
    max_min(a,0,size-1,max,min); 
    cout<<"Max="<<max<<endl; 
    cout<<"Min="<<min<<endl; 
    cout<<"Number of comp="<<Count<<endl; 
}

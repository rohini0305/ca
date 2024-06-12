#include <bits/stdc++.h>
using namespace std;
int partition(int a[], int low, int high)
{
    int pivote = a[low];
    int i = low, j = high;
    while (i < j)
    {
        while (a[i] <= pivote && i<= high-1)
        {
            i++;
        }
        while (a[j] > pivote && j >= low+1)
        {
            j--;
        }
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}
void qs(int a[], int low, int high)
{
    if (low < high)
    {
        int j = partition(a, low, high);
        qs(a, low, j - 1);
        qs(a, j + 1, high);
    }
}
int main()
{
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    int a[n];
    cout << "Enter the elements of an array:";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    qs(a,0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i]<<" ";
    }
    return 0;
}

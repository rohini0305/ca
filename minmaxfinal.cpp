#include <iostream>
using namespace std;
void minMax(int arr[], int i, int j, int &Max, int &Min)
{
    int Min1, Max1;
    if (i == j)
    {
        Min = Max = arr[i];
    }
    else if (i == j - 1)
    {
        if (arr[i] < arr[j])
        {
            Min = arr[i];
            Max = arr[j];
        }
        else
        {
            Min = arr[j];
            Max = arr[i];
        }
    }
    else
    {
        int mid = (i + j) / 2;
        minMax(arr, i, mid, Max, Min);
        minMax(arr, mid + 1, j, Max1, Min1);

        if (Min > Min1)
        {
            Min = Min1;
        }

        if (Max < Max1)
        {
            Max = Max1;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int Min, Max;
    minMax(arr, 0, n - 1, Max, Min);
    cout << "Minimum element: " << Min << endl;
    cout << "Maximum element: " << Max << endl;
    return 0;
}

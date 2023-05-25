#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        swap(arr[i], arr[min_index]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int n;

    cout << "Enter the size of array" << endl;
    cin >> n;

    int arr[n];

    cout << "Enter array elements" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "--------------------------" << endl;

    selection_sort(arr, n);

    return 0;
}
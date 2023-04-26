#include <bits/stdc++.h>
using namespace std;

/*
    This approach is considered greedy because at each step, the algorithm makes the locally optimal choice of selecting the smallest element,
    without considering the global or long-term effects of that choice.
     The algorithm simply aims to minimize the number of swaps needed to sort the array, without considering other factors such as the overall time complexity of the algorithm.
*/
void selectionsort(int arr[], int n)
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

        swap(arr[min_index], arr[i]);

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "------------" << endl;
    }
}

int main()
{
    int n;
    cout << "Enter size of arr:" << endl;
    cin >> n;

    cout << "Enter array elements" << endl;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "----------" << endl;
    cout << "----------" << endl;
    cout << "----------" << endl;

    selectionsort(arr, n);

    return 0;
}

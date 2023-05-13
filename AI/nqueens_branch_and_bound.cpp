#include <bits/stdc++.h>
using namespace std;

bool isSafe(int arr[], int x, int y, int n)
{
    // to check the row
    for (int row = 0; row < x; row++)
    {
        if (arr[row] == y || abs(row - x) == abs(arr[row] - y))
        {
            return false;
        }
    }

    return true; // if it's safe to place the queen
}

void nQueen(int arr[], int x, int n, int &count)
{
    if (x >= n)
    {
        count++; // found a solution, increment the count

        // print the solution
        cout << "Solution " << count << ":\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == j)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << "- ";
                }
            }
            cout << "\n";
        }
        cout << "\n";

        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x] = col;

            nQueen(arr, x + 1, n, count);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    int count = 0; // to count the number of solutions

    nQueen(arr, 0, n, count);

    return 0;
}

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

void nQueenBB(int arr[], int x, int n, int &count, bool cols[], bool diag1[], bool diag2[])
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
        if (!cols[col] && !diag1[x + col] && !diag2[x - col + n - 1])
        {
            arr[x] = col;
            cols[col] = diag1[x + col] = diag2[x - col + n - 1] = true;

            nQueenBB(arr, x + 1, n, count, cols, diag1, diag2);

            cols[col] = diag1[x + col] = diag2[x - col + n - 1] = false;
        }
    }
}

void nQueenBranchBound(int n)
{
    int arr[n];
    bool cols[n] = {false};          // to mark if a column is occupied
    bool diag1[2 * n - 1] = {false}; // to mark if a diagonal (from top-left to bottom-right) is occupied
    bool diag2[2 * n - 1] = {false}; // to mark if a diagonal (from top-right to bottom-left) is occupied

    int count = 0; // to count the number of solutions

    nQueenBB(arr, 0, n, count, cols, diag1, diag2);
}

int main()
{
    int n;
    cin >> n;

    nQueenBranchBound(n);

    return 0;
}

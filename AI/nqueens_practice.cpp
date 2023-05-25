#include <bits/stdc++.h>
using namespace std;

const int N = 20;

bool is_safe(int arr[][N], int x, int y, int n)
{

    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }

    // for left diagonal

    int row = x;
    int col = y;

    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    row = x;
    col = y;

    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool n_queens(int arr[][N], int x, int n)
{
    if (x >= n)
    {
        return true; // base condition
    }

    for (int col = 0; col < n; col++)
    {
        if (is_safe(arr, x, col, n))
        {
            arr[x][col] = 1;

            if (n_queens(arr, x + 1, n))
            {
                return true;
            }

            arr[x][col] = 0; // backtracking
        }
    }

    return false;
}

int main()
{

    int n;
    cin >> n;

    int arr[N][N];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (n_queens(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 20;

bool isSafe(int arr[][N], int x, int y, int n)
{
    // to check the row
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }

    // to check for diagonals
    // left diagonal
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
    return true; // if it's safe to place the queen
}

bool nQueen(int arr[][N], int x, int n)
{
    if (x >= n)
    {
        return true; // base condition when all queens are placed
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;

            if (nQueen(arr, x + 1, n))
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

    if (nQueen(arr, 0, n))
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

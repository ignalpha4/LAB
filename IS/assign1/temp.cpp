#include <bits/stdc++.h>
using namespace std;

void andfunction(string s, int n)
{

    string arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = s[i] & 127;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void xorfunction(string s, int n)
{

    string arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = s[i] ^ 127;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

int main()
{
    string s;

    cout << "Enter the string:" << endl;
    cin >> s;

    int n = s.length();

    andfunction(s, n);
    xorfunction(s, n);

    return 0;
}
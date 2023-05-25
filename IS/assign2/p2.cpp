#include <bits/stdc++.h>
using namespace std;

string remove_space(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

string encrypt(string msg, int depth)
{
    msg = remove_space(msg);
    int colsize = msg.length();

    char arr[depth][colsize];

    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < colsize; j++)
        {
            arr[i][j] = '\n';
        }
    }

    bool direction = false;
    int row = 0, col = 0;

    for (int i = 0; i < colsize; i++)
    {
        if (row == 0 || row == (depth - 1))
        {
            direction = !direction;
        }

        arr[row][col] = msg[i];
        col++;

        direction ? row++ : row--;
    }

    string result;

    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < colsize; j++)
        {
            if (arr[i][j] != '\n')
            {
                result.push_back(arr[i][j]);
            }
        }
    }

    return result;
}

string decrpyt(string cipher, int depth)
{

    int colsize = cipher.length();

    char arr[depth][colsize];

    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < colsize; j++)
        {
            arr[i][j] = '\n';
        }
    }

    bool direction = false;
    int row = 0, col = 0;

    for (int i = 0; i < colsize; i++)
    {
        if (row == 0 || row == (depth - 1))
        {
            direction = !direction;
        }

        arr[row][col] = '*';
        col++;

        direction ? row++ : row--;
    }

    int index = 0;

    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < colsize; j++)
        {
            if (arr[i][j] == '*' && index < colsize)
            {
                arr[i][j] = cipher[index++];
            }
        }
    }

    string result;
    row = 0, col = 0;

    for (int i = 0; i < colsize; i++)
    {
        if (row == 0)
        {
            direction = true;
        }
        if (row == (depth - 1))
        {
            direction = false;
        }

        if (arr[row][col] != '*')
        {
            result.push_back(arr[row][col++]);
        }

        direction ? row++ : row--;
    }

    return result;
}

int main()
{
    string msg;
    cout << "Enter msg to encrypt:";
    getline(cin, msg);

    int depth;
    cout << "enter the depth:";
    cin >> depth;

    string cipher = encrypt(msg, depth);
    cout << "Enccrypted msg is: " << cipher << endl;

    string plaintext = decrpyt(cipher, depth);
    cout << "decrypted msg is: " << plaintext << endl;

    return 0;
}
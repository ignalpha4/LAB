#include <bits/stdc++.h>
using namespace std;

string removespace(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

string encrypt(string msg, int depth)
{
    msg = removespace(msg);
    int col_size = msg.length();

    char arr[depth][col_size];

    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            arr[i][j] = '\n';
        }
    }

    bool direction = false;
    int row = 0, col = 0;

    for (int i = 0; i < col_size; i++)
    {
        if (row == 0 || row == (depth - 1))
        {
            direction = !direction;
        }

        arr[row][col] = msg[i];
        col++;

        direction ? row++ : row--;
    }

    string cipher;

    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            if (arr[i][j] != '\n')
            {
                cipher.push_back(arr[i][j]);
            }
        }
    }

    return cipher;
}

//-------------------decryption------------------------------------

string decrypt(string cipher, int depth)
{
    int col_size = cipher.length();

    char arr[depth][col_size];

    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            arr[i][j] = '\n';
        }
    }

    bool direction = false;
    int row = 0, col = 0;

    for (int i = 0; i < col_size; i++)
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
        for (int j = 0; j < col_size; j++)
            if (arr[i][j] == '*' && index < col_size)
                arr[i][j] = cipher[index++];

    string result;

    row = 0, col = 0;
    for (int i = 0; i < col_size; i++)
    {

        if (row == 0)
            direction = true;
        if (row == depth - 1)
            direction = false;

        if (arr[row][col] != '*')
            result.push_back(arr[row][col++]);

        direction ? row++ : row--;
    }
    return result;
}

//----------------------------------------------------------------
int main()
{

    string msg;
    cout << "Enter msg to encrypt:" << endl;
    getline(cin, msg);

    int depth;
    cout << "Enter depth" << endl;
    cin >> depth;

    string ciphertext = encrypt(msg, depth);

    cout << "Encrypted msg is:" << ciphertext << endl;

    //------------------------------------------------

    string plaintext = decrypt(ciphertext, depth);
    cout << "decrypted msg is: " << plaintext << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

// this is railfence approach 1] transposition->keyless-> type(1)railfence
/*
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); // for removing white space from the massege
    return str;
}




string rail_fence_encrypt(string plaintext, int key) {

    plaintext=removeSpaces(plaintext);

    vector<string> rail(key); // create vector of strings
    int row = 0;
    bool down = true;

    for (int i = 0; i < plaintext.length(); i++) {
        rail[row] += plaintext[i]; // add character to current row

        if (down) {
            row++;
        }
        else {
            row--;
        }

        if (row == key - 1) { // reached bottom row
            down = false;
        }
        else if (row == 0) { // reached top row
            down = true;
        }
    }

    string ciphertext = "";
    for (int i = 0; i < rail.size(); i++) { // concatenate rows to form ciphertext
        ciphertext += rail[i];
    }

    return ciphertext;
}

string rail_fence_decrypt(string ciphertext, int key) {
    ciphertext=removeSpaces(ciphertext);

    vector<string> rail(key); // create vector of strings
    vector<int> lengths(key, 0); // keep track of length of each row
    int row = 0;
    bool down = true;

    for (int i = 0; i < ciphertext.length(); i++) {
        rail[row] += "-"; // use a placeholder character
        lengths[row]++;

        if (down) {
            row++;
        }
        else {
            row--;
        }

        if (row == key - 1) { // reached bottom row
            down = false;
        }
        else if (row == 0) { // reached top row
            down = true;
        }
    }

    int index = 0;
    for (int i = 0; i < rail.size(); i++) { // replace placeholder characters with plaintext characters
        for (int j = 0; j < lengths[i]; j++) {
            rail[i][j] = ciphertext[index++];
        }
    }

    string plaintext = "";
    row = 0;
    down = true;

    for (int i = 0; i < ciphertext.length(); i++) {
        plaintext += rail[row][0]; // append first character of current row

        rail[row] = rail[row].substr(1); // remove first character of current row
        lengths[row]--;

        if (down) {
            row++;
        }
        else {
            row--;
        }

        if (row == key - 1) { // reached bottom row
            down = false;
        }
        else if (row == 0) { // reached top row
            down = true;
        }
    }

    return plaintext;
}
*/

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); // for removing white space from the message
    return str;
}

string encryptRailFence(string text, int key)
{
    text = removeSpaces(text);

    char rail[key][(text.length())];

        for (int i = 0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            rail[i][j] = '\n';

    // to find the direction
    bool dir_down = false;
    int row = 0, col = 0;

    for (int i = 0; i < text.length(); i++)
    {
        // check the direction of flow
        // reverse the direction if we've just
        // filled the top or bottom rail
        if (row == 0 || row == key - 1)
            dir_down = !dir_down;

        // fill the corresponding alphabet
        rail[row][col++] = text[i];

        // find the next row using direction flag
        // dir_down ? row++ : row--;
        if (dir_down == true)
        {
            row++;
        }
        else
        {
            row--;
        }
    }

    // now we can construct the cipher using the rail matrix
    string result;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            if (rail[i][j] != '\n')
                result.push_back(rail[i][j]);

    return result;
}

// This function receives cipher-text and key
// and returns the original text after decryption
string decryptRailFence(string cipher, int key)
{
    cipher = removeSpaces(cipher);
    // create the matrix to cipher plain text
    // key = rows , length(text) = columns
    char rail[key][cipher.length()];

    // filling the rail matrix to distinguish filled
    // spaces from blank ones
    for (int i = 0; i < key; i++)
        for (int j = 0; j < cipher.length(); j++)
            rail[i][j] = '\n';

    // to find the direction
    bool dir_down;

    int row = 0, col = 0;

    // mark the places with '*'
    for (int i = 0; i < cipher.length(); i++)
    {
        // check the direction of flow
        if (row == 0)
            dir_down = true;
        if (row == key - 1)
            dir_down = false;

        // place the marker
        rail[row][col++] = '*';

        // find the next row using direction flag
        dir_down ? row++ : row--;
    }

    // now we can construct the fill the rail matrix
    int index = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < cipher.length(); j++)
            if (rail[i][j] == '*' && index < cipher.length())
                rail[i][j] = cipher[index++];

    // now read the matrix in zig-zag manner to construct
    // the resultant text
    string result;

    row = 0, col = 0;
    for (int i = 0; i < cipher.length(); i++)
    {
        // check the direction of flow
        if (row == 0)
            dir_down = true;
        if (row == key - 1)
            dir_down = false;

        // place the marker
        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);

        // find the next row using direction flag
        dir_down ? row++ : row--;
    }
    return result;
}
int main()
{

    string plaintext;
    int key;
    cout << "Enter the msg to encrypt:" << endl;
    getline(cin, plaintext);

    cout << "Enter the rows:" << endl;
    cin >> key;

    string ciphertext = encryptRailFence(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedtext = decryptRailFence(ciphertext, key);
    cout << "Decryptedtext: " << decryptedtext << endl;

    return 0;
}

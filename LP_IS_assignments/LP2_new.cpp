#include<bits/stdc++.h>

using namespace std;


string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); // for removing white space from the massege
    return str;
}



//encryption 

string encrypt(string message, int num_cols)
{
    // remove spaces from the message
    message = removeSpaces(message);
    
    // calculate the number of rows
    int num_rows = ceil((double) message.length() / num_cols);
    
    // create a 2D array to hold the message
    char arr[num_rows][num_cols];
    
    // fill the array with the message
    int k = 0;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (k < message.length()) {
                arr[i][j] = message[k++];
            }
            else {
                arr[i][j] = ' ';
            }
        }
    }
    
    // read the array column by column to get the encrypted message
    string ciphertext = "";
    for (int j = 0; j < num_cols; j++) {
        for (int i = 0; i < num_rows; i++) {
            ciphertext += arr[i][j];
        }
    }
    
    return ciphertext;
}

// function to decrypt a message encrypted using columnar transposition
string decrypt(string ciphertext, int num_cols)
{
    // remove spaces from the ciphertext
    ciphertext = removeSpaces(ciphertext);
    
    // calculate the number of rows
    int num_rows = ceil((double) ciphertext.length() / num_cols);
    
    // create a 2D array to hold the decrypted message
    char arr[num_rows][num_cols];
    
    // fill the array with the ciphertext
    int k = 0;
    for (int j = 0; j < num_cols; j++) {
        for (int i = 0; i < num_rows; i++) {
            if (k < ciphertext.length()) {
                arr[i][j] = ciphertext[k++];
            }
            else {
                arr[i][j] = ' ';
            }
        }
    }
    
    // read the array row by row to get the decrypted message
    string message = "";
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            message += arr[i][j];
        }
    }
    
    return message;
}

int main()
{
    string message, ciphertext, decrypted;
    int num_cols;

    // get the message to encrypt
    cout << "Enter a message to encrypt: ";
    getline(cin, message);
    
    // get the number of columns to use for encryption
    cout << "Enter the number of columns to use for encryption: ";
    cin >> num_cols;
    
    // encrypt the message using columnar transposition
    ciphertext = encrypt(message, num_cols);
    cout << "Encrypted message: " << ciphertext << endl;
    
    // decrypt the message using columnar transposition
    decrypted = decrypt(ciphertext, num_cols);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
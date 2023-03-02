#include <bits\stdc++.h>

using namespace std;

string keylessTranspositionRowCipher(string plaintext, int numRows) {
    string ciphertext;
    int cycleLen = 2 * numRows - 2;  // Calculate the length of each cycle

    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < plaintext.length(); j += cycleLen) {
            ciphertext += plaintext[j];  // Add the character at index j to the ciphertext
            if (i != 0 && i != numRows - 1 && j + cycleLen - 2 * i < plaintext.length()) {
                ciphertext += plaintext[j + cycleLen - 2 * i];  // Add the character at the offset index to the ciphertext
            }
        }
    }

    return ciphertext;
}



int main() {
    string plaintext;
    int numRows;

    cout << "Enter the Plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the Row Size: ";
    cin >> numRows;

    string ciphertext = keylessTranspositionRowCipher(plaintext, numRows);
    cout << "Ciphertext: " << ciphertext << endl;

    string originalmsg = keylessTranspositionRowDecipher(ciphertext, numRows);
    cout << "Decrypted message: " << originalmsg << endl;

    return 0;
}

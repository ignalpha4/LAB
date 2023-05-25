#include <bits/stdc++.h>
using namespace std;

string generate_response(string input)
{

    map<string, string> keywords = {
        {"hello", "hi"},
        {"how are you", "i am fine "},
        {"history", "history is study of past events"}

    };

    for (auto it = keywords.begin(); it != keywords.end(); ++it)
    {
        if (input.find(it->first) != string::npos)
        {
            return it->second;
        }
    }

    string responses[] = {"i am sorry", "i didnt get that", "cant understand", "bla bla bla"};
    int index = rand() % 4;

    return responses[index];
}

int main()
{

    string input;

    cout << "I am educational chatbot" << endl;
    cout << "what would you like to know about" << endl;

    while (true)
    {
        getline(cin, input);

        string output = generate_response(input);

        cout << output << endl;

        cout << "any other topic" << endl;
    }

    return 0;
}
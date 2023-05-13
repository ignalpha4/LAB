#include <bits/stdc++.h>

using namespace std;

string generateResponse(string input)
{
    map<string, string> keywords = {
        {"hello", "Hi there! How can I help you?"},
        {"goodbye", "Goodbye! Have a great day."},
        {"thanks", "You're welcome!"},
        {"hello", "Hi there! How can I help you?"},
        {"solar system", "The solar system consists of the Sun and the objects that orbit it, including eight planets, dwarf planets, and various other celestial bodies."},
        {"programming", "Programming is the process of designing, writing, testing, and maintaining computer programs."},
        {"history", "History is the study of past events, particularly in human affairs."},
        {"art", "Art is the expression of human creativity and imagination, typically in a visual form such as painting, sculpture, or architecture."},
        {"geography", "Geography is the study of the earth's physical features and  the living creatures that inhabit it."},
        {"literature", "Literature is a form of written or spoken art that uses language to evoke emotion and convey ideas."},
        {"mathematics", "Mathematics is the study of numbers, quantities, and shapes."},
        {"music", "Music is an art form that uses sound and silence to create a composition that expresses emotion or tells a story."},
        {"philosophy", "Philosophy is the study of the fundamental nature of knowledge, reality, and existence."},
        {"physics", "Physics is the study of matter, energy, and the interactions between them."},
        {"psychology", "Psychology is the scientific study of behavior and mental processes."},
    };
    for (auto it = keywords.begin(); it != keywords.end(); ++it)
    {
        if (input.find(it->first) != string::npos)
        {
            return it->second;
        }
    }

    string responses[] = {"I'm not sure what you're asking.", "Can you please be more specific?", "I don't understand. Can you rephrase your question?", "I'm sorry, I didn't catch that."};
    int index = rand() % 4;
    return responses[index];
}

int main()
{

    cout << "Hi, I'm an Educational AI chatbot. What can I help you with today?" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    string input;
    while (true)
    {
        getline(cin, input);
        if (input == "bye")
        {
            cout << "Goodbye! Have a great day." << endl;
            break;
        }
        string response = generateResponse(input);
        cout << "-----------------------------------------------" << endl;
        cout << response << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "any other topic?" << endl;
    }

    return 0;
}

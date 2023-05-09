#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Define a map to hold information about different topics
    map<string, string> topics;
    topics["solar system"] = "The solar system consists of the Sun and the objects that orbit it, including eight planets, dwarf planets, and various other celestial bodies.";
    topics["programming"] = "Programming is the process of designing, writing, testing, and maintaining computer programs.";
    topics["history"] = "History is the study of past events, particularly in human affairs.";
    topics["art"] = "Art is the expression of human creativity and imagination, typically in a visual form such as painting, sculpture, or architecture.";
    topics["geography"] = "Geography is the study of the earth's physical features and the living creatures that inhabit it.";
    topics["literature"] = "Literature is a form of written or spoken art that uses language to evoke emotion and convey ideas.";
    topics["mathematics"] = "Mathematics is the study of numbers, quantities, and shapes.";
    topics["music"] = "Music is an art form that uses sound and silence to create a composition that expresses emotion or tells a story.";
    topics["philosophy"] = "Philosophy is the study of the fundamental nature of knowledge, reality, and existence.";
    topics["physics"] = "Physics is the study of matter, energy, and the interactions between them.";
    topics["psychology"] = "Psychology is the scientific study of behavior and mental processes.";

    // Greeting message
    cout << "Hi, I'm an educational chatbot. What topic would you like to learn about today?" << endl;

    // Main loop
    while (true)
    {
        // Read user input
        string input;
        getline(cin, input);

        // Check if the user wants to quit
        if (input == "bye")
        {
            cout << "Goodbye!" << endl;
            break;
        }

        // Look up information about the user's topic
        auto it = topics.find(input);
        if (it != topics.end())
        {
            cout << it->second << endl;
        }
        else
        {
            cout << "I'm sorry, I don't know about that topic. Could you please choose another topic?" << endl;
        }
    }

    return 0;
}

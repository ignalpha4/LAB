#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Book
{
public:
    string title;
    string author;
    string genre;

    Book(string t, string a, string g) : title(t), author(a), genre(g) {}
};

class ExpertSystem
{
private:
    unordered_map<string, vector<Book>> database;

public:
    ExpertSystem()
    {

        database["Fiction"] = {
            {"To Kill a Mockingbird", "Harper Lee", "Fiction"},
            {"1984", "George Orwell", "Fiction"},
            {"Pride and Prejudice", "Jane Austen", "Fiction"}};
        database["Non-fiction"] = {
            {"The Selfish Gene", "Richard Dawkins", "Non-fiction"},
            {"Thinking, Fast and Slow", "Daniel Kahneman", "Non-fiction"},
            {"The Art of War", "Sun Tzu", "Non-fiction"}};
        database["Biography"] = {
            {"Steve Jobs", "Walter Isaacson", "Biography"},
            {"The Autobiography of Malcolm X", "Malcolm X", "Biography"},
            {"A Beautiful Mind", "Sylvia Nasar", "Biography"}};

        database["Science Fiction"] = {
            {"Dune", "Frank Herbert", "Science Fiction"},
            {"Ender's Game", "Orson Scott Card", "Science Fiction"},
            {"The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "Science Fiction"}};
        database["Mystery"] = {
            {"The Girl with the Dragon Tattoo", "Stieg Larsson", "Mystery"},
            {"Gone Girl", "Gillian Flynn", "Mystery"},
            {"The Da Vinci Code", "Dan Brown", "Mystery"}};
        database["Fantasy"] = {
            {"The Lord of the Rings", "J.R.R. Tolkien", "Fantasy"},
            {"Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "Fantasy"},
            {"A Game of Thrones", "George R.R. Martin", "Fantasy"}};
    }

    vector<Book> getBookRecommendations(string interest)
    {
        vector<Book> recommendations;
        for (auto category : database)
        {
            for (auto book : category.second)
            {
                if (book.genre == interest)
                {
                    recommendations.push_back(book);
                }
            }
        }
        return recommendations;
    }
};

int main()
{
    ExpertSystem es;

    cout << "Enter the topic of interest: ";
    string topic;
    getline(cin, topic);

    vector<Book> recommendations = es.getBookRecommendations(topic);

    cout << "Recommendations for " << topic << ":" << endl;
    if (recommendations.empty())
    {
        cout << "No recommendations found for " << topic << "." << endl;
    }
    else
    {
        for (const auto &book : recommendations)
        {
            cout << book.title << " by " << book.author << endl;
        }
    }

    return 0;
}

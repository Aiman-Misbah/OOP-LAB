#include <iostream>
using namespace std;

class Level
{
private:
    int levelNumber;
    string difficulty;

public:
    Level() : levelNumber(0), difficulty("Unknown") {}

    Level(int levelNumber, string difficulty) : levelNumber(levelNumber), difficulty(difficulty) {}

    void displayLevel() const
    {
        cout << "Level Number: " << levelNumber << endl;
        cout << "Difficulty: " << difficulty << endl;
    }
};

class VideoGame
{
private:
    string title;
    string genre;
    Level *levels;
    int levelCount;

public:
    VideoGame(string title, string genre, int levelCount, int levelNumbers[], string difficulties[]) : title(title), genre(genre), levelCount(levelCount)
    {
        levels = new Level[levelCount];
        for (int i = 0; i < levelCount; i++)
        {
            levels[i] = Level(levelNumbers[i], difficulties[i]);
        }
    }

    void displayDetails() const
    {
        cout << "Game: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Levels: " << endl;
        for (int i = 0; i < levelCount; i++)
        {
            levels[i].displayLevel();
        }
    }

    ~VideoGame()
    {
        cout << "Deleting Game: " << title << " Along with its Levels...." << endl;
        delete[] levels;
    }
};

int main()
{
    int levelNumbers[3] = {1, 2, 3};
    string difficulties[3] = {"Easy", "Medium", "Hard"};
    VideoGame game1("Free Fire", "Action", 3, levelNumbers, difficulties);
    cout << endl;
    cout << "----------Games----------" << endl;
    game1.displayDetails();
    cout << endl;
    VideoGame game2("PUBG", "Thriller", 3, levelNumbers, difficulties);
    game2.displayDetails();
    cout << endl;
    return 0;
}


#include <iostream>
using namespace std;
#define maxSongs 15

class MusicPlayer
{
private:
    string playlist[maxSongs];
    string currentlyPlayingSong;
    int songCount = 0;

public:
    void addSongs()
    {
        if (songCount >= maxSongs)
        {
            cout << "Playlist is full. Cannot add more songs!" << endl;
            return;
        }

        cout << "Enter song name: ";
        cin.ignore();
        getline(cin, playlist[songCount]);
        songCount++;
        cout << "Song added successfully!" << endl;
    }

    void removeSongs()
    {
        if (songCount == 0)
        {
            cout << "The playlist is empty. No songs to remove!" << endl;
            return;
        }

        string song;
        cout << "Enter the song to remove: ";
        cin.ignore();
        getline(cin, song);

        bool found = false;
        for (int i = 0; i < songCount; i++)
        {
            if (playlist[i] == song)
            {
                found = true;
                for (int j = i; j < songCount - 1; j++)
                {
                    playlist[j] = playlist[j + 1];
                }
                playlist[songCount - 1] = "";
                songCount--;
                cout << song << " has been removed from the playlist." << endl;
                return;
            }
        }
        if (!found)
        {
            cout << song << " is not in the playlist!" << endl;
        }
    }

    void displayPlaylist()
    {
        if (songCount == 0)
        {
            cout << "The playlist is empty!" << endl;
            return;
        }

        cout << "Current Playlist:" << endl;
        for (int i = 0; i < songCount; i++)
        {
            cout << (i + 1) << ". " << playlist[i] << endl;
        }
    }

    void playSong()
    {
        if (songCount == 0)
        {
            cout << "No songs available to play!" << endl;
            return;
        }

        string song;
        cout << "Enter the song to play: ";
        cin.ignore();
        getline(cin, song);

        bool found = false;
        for (int i = 0; i < songCount; i++)
        {
            if (playlist[i] == song)
            {
                currentlyPlayingSong = song;
                found = true;
                cout << "Currently Playing: " << currentlyPlayingSong << endl;
                return;
            }
        }
        if (!found)
        {
            cout << "The song '" << song << "' is not in the playlist!" << endl;
        }
    }
};

int main()
{
    MusicPlayer Imran;
    int choice;

    do
    {
        cout << "\n---------- Music Player Menu ----------\n";
        cout << "1. Add Song\n";
        cout << "2. Remove Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Play Song\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Imran.addSongs();
            break;
        case 2:
            Imran.removeSongs();
            break;
        case 3:
            Imran.displayPlaylist();
            break;
        case 4:
            Imran.playSong();
            break;
        case 5:
            cout << "Exiting Music Player. Have a great day!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}


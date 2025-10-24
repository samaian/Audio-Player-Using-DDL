#include <iostream>
#include "Playlists.h"
#include"PlaylistInfo.h"
#include"DoublyLinkedList.h"
#include "Surah.h"
#include <iomanip>
#include<string>
#define table cout << left << setw(25) << setfill(' ')
#define equals cout << "=============================================================================================================================================================================\n";
#define nice cout <<setw(37)<<"=";
#define decore cout <<"==================================================================\n";

using namespace std;
void start() {
    PlaySound(TEXT("004.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void welcome() {
    start();
    cout << endl;
    cout << endl;
    std::cout << "                                   +=================================================================+" << std::endl;
    std::cout << "                                   |                Welcome to our Qu'ran Playlist Manager           |" << std::endl;
    std::cout << "                                   +=================================================================+" << std::endl;
    cout << endl;
    cout << "====================================================================================================================================================\n";
    cout << endl;


}

void printMenu() {
    cout << "                                        +=======================================================+" << endl;
    cout << "                                        |                Qu'ran Playlist Manager Menu           |" << endl;
    cout << "                                        +=======================================================+" << endl;
    cout << "                                        | 1. Add a new playlist                                 |" << endl;
    cout << "                                        | 2. Add Shurah to an existing playlist                 |" << endl;
    cout << "                                        | 3. Remove Shurah from an existing playlist            |" << endl;
    cout << "                                        | 4. Update the order of existing playlist              |" << endl;
    cout << "                                        | 5. Display All Current Playlists                      |" << endl;
    cout << "                                        | 6. Display all Playlists Shurah                       |" << endl;
    cout << "                                        | 7. Display Shurah in a specific playlist              |" << endl;
    cout << "                                        | 8. Play Shurah from specific playlist                 |" << endl;
    cout << "                                        |    Use left arrow (<-) to play the previous shurah    |" << endl;
    cout << "                                        |    Use right arrow (->) to play the next shurah       |" << endl;
    cout << "                                        |    Use up arrow (^) to pause the current shurah       |" << endl;
    cout << "                                        |    Use down arrow (v) to resume the current shurah    |" << endl;
    cout << "                                        |    Press q to exit current playlist & return to menu  |" << endl;
    cout << "                                        | 9. Save an existing playlist to a file                |" << endl;
    cout << "                                        | 10. Load an existing playlist from a file             |" << endl;
    cout << "                                        | 11. Remove an existing playlist                       |" << endl;
    cout << "                                        | 12. Exit                                              |" << endl;
    cout << "                                        +=======================================================+" << endl;
    cout << "                                                           Your choice: ";
}

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void loadingg() {
    const int barWidth = 20;
    const int squareSize = 5;
    char x = 254;
    cout << "\n";

    for (int i = 0; i <= barWidth; i++) {
        setColor(i);
        cout << "\r[";
        for (int j = 0; j < i; ++j) {
            for (int y = 0; y < squareSize; ++y) {
                cout << x;
            }
        }

        for (int j = i; j < barWidth; ++j) {
            for (int y = 0; y < squareSize; ++y) {
                cout << " ";
            }
        }

        cout << "] " << (i * 100 / barWidth) << "%";
        cout.flush();
        Sleep(200);
    }

    cout << "\nLoading Complete!\n";
}


int main() {
    string correctPassword = "123";
    string userInput;
    string userName;
    loadingg();
    setColor(11);
    cout << "Please Enter Your UserName : ";
    cin >> userName;
    cout << "Enter the password: ";
    char ch;
    while (true) {
        ch = _getch();
      /*  if (ch == 13) {
            break;
        }
        else if (ch == 8) {
            if (userInput.length() > 0) {
                userInput.pop_back();
                cout << "\b \b";
            }
        }
        else {*/
            userInput.push_back(ch);
            cout << "*";
        
    }

    cout << endl;

    if (userInput == correctPassword) {
        cout << "Correct password!\nPress Enter to continue..." << endl;
        cin.ignore();
        cin.get();

        welcome();
        Playlists l;
        PlaylistInfo surah;
        Surah s;
        int c = 0;
        int choice;

        do {
            for (int i = 0; i < 1; i++) {
                printMenu();
                cin >> choice;
            }

            switch (choice) {
            case 1: {
                nice decore cout << setw(37) << "|" << "                         ADD New Playlist                        |\n";
                nice decore
                   
                string nameplaylist;
                cout << "Enter the name of playlist: ";
                cin >> nameplaylist;
                l.addPlaylist(nameplaylist);
                surah.setName(nameplaylist);
                c++;
                break;
            }
            case 2: {
                nice decore cout << setw(37) << "|" << "                         ADD New Surah                           |\n";
                nice decore
                    Surah s2; 
                string n2;
                cout << "Enter Playlist name: ";
                cin >> n2;
                if (l.findPlaylist(n2)) {
                    string name6, type, reader;
                    string path;
                    bool fav;
                    cout << "Enter Surah Name: ";
                    cin >> name6;
                    cout << "Enter Surah Type: ";
                    cin >> type;
                    cout << "Enter Surah path: ";
                    cin >> path;
                    cout << "Enter Surah Reader: ";
                    cin >> reader;
                    cout << "Favorite or not (fav:1,not fav:0): ";
                    cin >> fav;
                    s2 = Surah(name6, type, reader, path, fav);
                    PlaylistInfo* p = l.findPlaylist(n2);
                    p->addSurahToPlaylist(s2);
                }
                else {
                    cout << "Playlist Not Found..\n";
                }
                break;
            }
            case 3: {
                nice decore cout << setw(37) << "|" << "                            Remove Surah                         |\n";
                nice decore
                    string n2;
                cout << "Enter Playlist name: "; cin >> n2;
                if (l.findPlaylist(n2)) {
                    string dname;
                    cout << "Enter Surah Name: "; cin >> dname;
                    PlaylistInfo* p = l.findPlaylist(n2);
                    p->removeSurah(dname);
                }
                else {
                    cout << "Playlist Not Found..\n";
                }
                break;
            }
            case 4: {
                nice decore cout << setw(37) << "|" << "                           Update order                          |\n";
                nice decore
                    string n2;
                cout << "Enter Playlist name: "; cin >> n2;
                if (l.findPlaylist(n2)) {
                    string dname;
                    int pos;
                    cout << "Enter Surah Name: "; cin >> dname;
                    cout << "Enter new position: "; cin >> pos;
                    PlaylistInfo* p = l.findPlaylist(n2);
                    p->UpdateOrder(dname, pos);
                }
                else {
                    cout << "Playlist Not Found..\n";
                }
                break;
            }
            case 5: {
                nice decore cout << setw(37) << "|" << "                       Dispaly all Playlists                     |\n";
                nice decore
                    l.displayAllPlaylists();
                break;
            }
            case 6: {
                nice decore cout << setw(37) << "|" << "                        Display all Surahs                       |\n";
                nice decore
                    cout << "Playlist Names:\n";
                for (int i = 1; i <= l.getSize(); i++) {
                    PlaylistInfo* playlist = l.getpos(i);  
                    if (playlist) {
                        cout << playlist->getName() << "\n";
                        playlist->displaySurahs();  
                    }
                    else {
                        cout << "Error: Playlist not found at index " << i << "\n";
                    }
                }
                break;
            }

            case 7: {
                nice decore cout << setw(37) << "|" << "                  Dispaly surahs in a Playlist                   |\n";
                nice decore
                    string pname2;
                cout << "Enter Playlist Name: "; cin >> pname2;
                l.printPlaylist(pname2);
                break;
            }

            case 8: {
                nice decore cout << setw(37) << "|" << "                  play surahs in a Playlist                   |\n";
                nice decore
                    cout << "Enter the playlist name to play: ";
                string playlistName;
                cin >> playlistName;

                PlaylistInfo* selectedPlaylist = l.findPlaylist(playlistName);
                if (!selectedPlaylist) {
                    cout << "Playlist not found." << endl;
                    break;
                }

                cout << "Starting playback for playlist: " << playlistName << endl;

                selectedPlaylist->playSurah();


                bool exitPlayback = false;
                while (!exitPlayback) {
                    cout << "Press an arrow key (or 'q' to exit playback): ";
                    char ch = _getch();
                    switch (ch) {
                    case 75: // Left arrow
                        selectedPlaylist->playPrevious();
                        break;
                    case 77: // Right arrow
                        selectedPlaylist->playNext();
                        break;
                    case 72: // Up arrow
                        selectedPlaylist->pauseSurah();
                        break;
                    case 80: // Down arrow
                        selectedPlaylist->resumeSurah();
                        break;
                    case 'q': // Quit playback
                    case 'Q':
                        cout << "Exiting playback..." << endl;
                        selectedPlaylist->pauseSurah();
                        exitPlayback = true;

                        break;

                    }
                }
                break;
            }


            case 9: {
                nice
                    decore
                    cout << setw(37) << "|" << "                           Save to File                          |\n";
                nice
                    decore
                    string filename;
                cout << "Enter file name : ";
                cin >> filename;
                l.saveToFile(filename);
                break;
            }
            case 10: {


                nice decore cout << setw(37) << "|" << "                         Load from File                          |\n";
                nice decore
                string playlistName,s; 
                cout << "Enter file name : ";
                cin >> s;
                cout << "which playlist you want to load from this file ? ";
                cin >> playlistName;
                l.loadFromFile(s, playlistName);
                break;
            }

            case 11: {
                nice decore cout << setw(37) << "|" << "                         Remove Playlist                         |\n";
                nice decore
                    string name;
                cout << "Enter the name of the playlist to remove: ";
                cin >> name;
                l.removePlaylist(name);
                break;
            }
            case 12:
                cout << "Exiting the program. Goodbye (: \n";
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
                break;
            }
        } while (choice != 13);
        return 0;
    }
    else {
        cout << "Incorrect password. \n";
        return 0;
    }

}

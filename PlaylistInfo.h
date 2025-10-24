#pragma once
#ifndef PLAYLISTINFO_H
#define PLAYLISTINFO_H
#include <string>
#include "DoublyLinkedList.h"
#include "Surah.h"
#define byte _win_byte
#include <windows.h>
#undef byte
#include<mmsystem.h>
#include<conio.h>
#include<fstream>
#include<sstream>
#include<vector>
#include <iomanip>
#include<map>
using namespace std;

#define equalsinfile << "======================================================================================================================================================================\n";
class PlaylistInfo {
private:
    string name;
    DoublyLinkedList<Surah> surahs;
    bool isPaused = false;
    bool isPlaying = false;
    Surah* currentSurah = nullptr;


public:
    PlaylistInfo() : name("") {}
    PlaylistInfo(const string& name) : name(name) {}
    bool operator==(PlaylistInfo& p) {
        return name == p.name;
    }
    string getName() const { return name; }

    void setName(const string& n) { name = n; }

    void addSurahToPlaylist(const Surah& surah) {
        surahs.Append(surah);
        cout << "Current Playlist Surahs:\n";
        cout << "====================================================================================================================================================\n";
        cout << left << setw(30) << "Surah Name"
            << setw(25) << "Type"
            << setw(30) << "Reader"
            << setw(35) << "Path"
            << setw(10) << "Favorite" << endl;
        cout << "====================================================================================================================================================\n";
        surahs.display();
        cout << "====================================================================================================================================================\n";
    }
    

    Surah* search(const string& n) {
        return surahs.Search(n);
    }

    void removeSurah(const string& surahName) {
        Surah* s = search(surahName);
        if (!s) {
            cout << "Surah '" << surahName << "' not found in playlist '" << name << "'." << endl;
            return;
        }

        if (!surahs.Remove(*s)) {
            cout << "Surah '" << surahName << "' not found in playlist '" << name << "'." << endl;
        }
        else {
            cout << "Surah '" << surahName << "' removed from playlist '" << name << "'." << endl;
            cout << "Current Playlist Surahs:\n";
            cout << "====================================================================================================================================================\n";
            cout << left << setw(30) << "Surah Name"
                << setw(25) << "Type"
                << setw(30) << "Reader"
                << setw(35) << "Path"
                << setw(10) << "Favorite" << endl;
            cout << "====================================================================================================================================================\n";
            surahs.display();
            cout << "====================================================================================================================================================\n";
        }
    }

    Surah* getpos(int pos) {
        return surahs.getNode(pos);
    }

    friend ostream& operator<<(ostream& os, const PlaylistInfo& playlist) {
        os << "Playlist Name: " << playlist.name;
        return os;
    }
    void displaySurahs() {
        if (surahs.isEmpty()) {
            cout << "There are no Surahs in playlist " << name << endl;
        }
        else {
            cout << "Surahs in Playlist: " << name << endl;
            cout << "====================================================================================================================================================\n";
            cout << left << setw(30) << "Surah Name"
                << setw(25) << "Type"
                << setw(30) << "Reader"
                << setw(35) << "Path"
                << setw(10) << "Favorite" << endl;
            cout << "====================================================================================================================================================\n";

            surahs.display();
        }
        cout << "====================================================================================================================================================\n";
    }


    Surah* getSurahInfo(string& surahName) {
        Surah* found = surahs.Search(surahName);
        if (found) {
            return found;
        }
        return nullptr;
    }

    void playSurah() {
        if (!currentSurah) {

            if (surahs.getHead()) {
                currentSurah = &surahs.getHead()->data;
                return;
            }
            else {
                cout << "No Surah to play." << endl;
                return;
            }
        }

        if (currentSurah) {
            cout << "Playing Surah: " << currentSurah->getName() << endl;
            PlaySoundA(currentSurah->spath().c_str(), NULL, SND_ASYNC);
            isPlaying = true;
            isPaused = false;
        }
        else {
            cout << "No Surah to play." << endl;
        }
    }

    void pauseSurah() {
        if (isPlaying) {
            cout << "Pausing Surah." << endl;
            PlaySound(NULL, NULL, 0);
            isPlaying = false;
            isPaused = true;
        }
    }

    void resumeSurah() {
        if (isPaused) {
            cout << "Resuming Surah: " << currentSurah->getName() << endl;

            PlaySoundA(currentSurah->spath().c_str(), NULL, SND_ASYNC);
            isPaused = false;
            isPlaying = true;
        }
    }

    void playNext() {
        if (currentSurah) {
            Node<Surah>* nextNode = surahs.findNode(*currentSurah)->next;
            if (nextNode) {
                currentSurah = &nextNode->data;
                cout << "Playing next Surah: " << currentSurah->getName() << endl;
                playSurah();
            }
            else {
                cout << "No next Surah available." << endl;
            }
        }
        else {
            cout << "No current Surah set." << endl;
        }
    }


    void playPrevious() {
        if (currentSurah) {
            Node<Surah>* prevNode = surahs.findNode(*currentSurah)->prev;
            if (prevNode) {
                currentSurah = &prevNode->data;
                playSurah();
            }
            else {
                cout << "No previous Surah available." << endl;
            }
        }
    }


    void displaySurahsInFile(fstream& fn) {
        vector<Surah>vc = surahs.displayInFile();
        int n = vc.size();
        fn equalsinfile
            fn << left << setw(25) << setfill(' ') << "ID";
        fn << left << setw(25) << setfill(' ') << "Surah Name";
        fn << left << setw(25) << setfill(' ') << "Surah Reader";
        fn << left << setw(25) << setfill(' ') << "Surah Path";
        fn << left << setw(25) << setfill(' ') << "Surah Type";
        fn << left << setw(25) << setfill(' ') << "Favorite";
        fn << "\n";
        fn equalsinfile
            for (int i = 0; i < n; ++i)
            {
                fn << left << setw(25) << setfill(' ') << i + 1;
                fn << left << setw(25) << setfill(' ') << vc[i].getName();
                fn << left << setw(25) << setfill(' ') << vc[i].getReder();
                fn << left << setw(25) << setfill(' ') << vc[i].spath();
                fn << left << setw(25) << setfill(' ') << vc[i].getType();
                fn << left << setw(25) << setfill(' ') << (vc[i].fav() ? "Yes" : "No");

                fn << "\n";
            }
        fn equalsinfile
    }

    void UpdateOrder(string& surahName, int pos) {
        Surah s = surahs.Searchtoupdate(surahName);

        if (s.getName().empty()) {
            cout << "Update failed: Surah not found!" << endl;
            return;
        }

        int i = surahs.findIndx(s);
        if (i == -1) {
            cout << "Update failed: Surah index not found!" << endl;
            return;
        }

        surahs.DeleteAtPosition(i);
        surahs.InsertAtPosition(s, pos);
    }

};

#endif // PLAYLISTINFO_H

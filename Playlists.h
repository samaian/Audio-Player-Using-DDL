#pragma once
#ifndef PLAYLISTS_H
#define PLAYLISTS_H
#include <iostream>
#include "DoublyLinkedList.h"
#include "PlaylistInfo.h"
#include <vector>
using namespace std;
class Playlists {
private:
    DoublyLinkedList<PlaylistInfo> playlists;
    PlaylistInfo* p;
public:
    void addPlaylist(string& name) {
        playlists.Append(PlaylistInfo(name));
        cout << "Playlist '" << name << "' added." << endl;
    }
    PlaylistInfo* search(string& n) {
        return playlists.Search(n);
    }

    void removePlaylist(string& playName) {
        PlaylistInfo* s = search(playName);
        if (!s) {
            cout << "Surah '" << playName << "' not found in playlists.'" << endl;
            return;
        }

        if (!playlists.Remove(*s)) {
            cout << "Surah '" << playName << "' not found in playlists .'" << endl;
            return;
        }
        else {
            cout << "Surah '" << playName << "' removed from playlists. '" << endl;
            return;
        }
       
    }
    PlaylistInfo* getpos(int pos) {
        return playlists.getNode(pos);
    }

    void displayAllPlaylists() const {
        cout << "All Playlists: " << endl;
        playlists.display2();
        cout << endl;
    }


    int getSize() {
        return playlists.getSize();
    }

    PlaylistInfo* findPlaylist(string& name) {
        return playlists.Search(name);
    }
    void printPlaylist(string playlistname) {
        PlaylistInfo* playlist = findPlaylist(playlistname);

        if (playlist) {
            cout << "Playlist: " << playlist->getName() << endl;
            playlist->displaySurahs();
        }
        else {
            cout << "Playlist with the name '" << playlistname << "' not found." << endl;
        }
    }

   
    void loadFromFile(const string& filename, string pname) {

        ifstream in(filename);

        fstream file;
        file.open(filename);
        if (!file.is_open()) {
            cout << "Error opening file : " << filename << " for reading\n";
            return;
        }
        string line; in >> line;
        addPlaylist(pname);
        vector<string> read;
        string name, reader, path, type;
        string x = "";
        for (int i = 0; line[i] != '?'; i++) {
            if (line[i] != ',')
                x += line[i];
            else {

                read.push_back(x);
                x = "";
                if (read.size() == 4) {
                    name = read[0];
                    reader = read[2];
                    type = read[1];
                    path = read[3];
                    read.resize(0);

                    Surah cur(name, type, reader, path, 1);
                    PlaylistInfo* p = findPlaylist(pname);
                    if (p) {
                        p->addSurahToPlaylist(cur);
                    }
                }

            }
        }
    }

    

    void saveToFile(const string& filename) {
        std::fstream file;
        file.open(filename, ios::out);
        if (!file.is_open())
        {
            cout << "Error opening file for writing: " << filename << endl;
            return;
        }
        cout << "What is the name of playlist you want ?.. ";
        string name;
        cin >> name;
        if (playlists.Search(name)) {
            PlaylistInfo* p = playlists.Search(name);
            p->displaySurahsInFile(file);
            file.close();

            cout << name << " Playlist saved successfully !\n";
        }
    }
};
#endif 


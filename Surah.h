#pragma once
#ifndef SURAH_H
#define SURAH_H
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
#pragma comment(lib, "winmm.lib")
class Surah {
private:
    string name;
    string type;
    string path;
    string reader;
    bool favorite;
public:
    Surah() {}
    Surah(const string& name, const string& type, const string& reader, const string& path, bool favorite)
        : name(name), type(type), reader(reader), path(path), favorite(favorite) {
    }


    bool operator==(const Surah& other) {
        return name == other.name && type == other.type && path == other.path
            && reader == other.reader && favorite == other.favorite;
    }

    Surah& operator=(const Surah& other) {
        if (this != &other) {
            name = other.name;
            type = other.type;
            reader = other.reader;
            path = other.path;
            favorite = other.favorite;
        }
        return *this;
    }


    string getName() { return name; }
    bool fav() { return favorite; }
    string getType() { return type; }
    string getReder() { return reader; }
    string spath() { return path; }
    friend ostream& operator<<(ostream& os, Surah& surah) {
        os << left << setw(30) << surah.getName()
            << setw(25) << surah.getType()
            << setw(30) << surah.getReder()
            << setw(35) << surah.spath()
            << setw(10) << (surah.fav() ? "Yes" : "No")<<endl;
        return os;
    }

};

#endif // SURAH_H


#include "listofsongs.h"
#include <fstream>

std::string getLocName(std::string str){};

ListOfSongs::ListOfSongs()
{
    std::ifstream read("playlist");
    std::string loc;
    while (getline(read, loc)){

        Song song;
        song.setLoc(loc);
        song.setName(getLocName(loc));
        songs.push_back(song);

    }
}

void ListOfSongs::add(QStringList files){
    for (int i = 0; i < files.size(); i++){
        Song song;
        song.setLoc(files[i].toStdString());
        song.setName(getLocName(files[i].toStdString()));
        songs.push_back(song);
    }
}

void ListOfSongs::del(int ind){
    songs.erase(songs.begin() + ind);
}

void ListOfSongs::save(){
    std::ofstream write("playlist");
    for (int i = 0; i < songs.size(); i++){
        write << songs[i].getLoc() << std::endl;
    }
}

QStringList ListOfSongs::getNameOfSongInList(){
    QStringList list;
    for (int i = 0; i < songs.size(); i++){
        QString qs = QString::fromStdString(songs[i].getName());
        list.push_back(qs);
    }
    return list;
}

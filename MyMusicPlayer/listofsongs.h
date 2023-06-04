#ifndef LISTOFSONGS_H
#define LISTOFSONGS_H

#include <QStringList>
#include <string>
#include "song.h"

std::string getLocName(std::string str);

class ListOfSongs
{
public:
    ListOfSongs();
    void add(QStringList files);
    void del(int ind);
    void save();

    QStringList getNameOfSongInList();
    QList<Song> songs;
    //QStringList getRoutes();

    int flag = 0;
};




#endif // LISTOFSONGS_H

#ifndef SONG_H
#define SONG_H

#include <string>

class Song
{
public:
    Song();

    std::string getName();
    std::string getLoc();
    //std::string getRoute();

    void setName(std::string n);
    void setLoc(std::string l);
    //void setRoute(std::string r);

private:
    std::string name = "";
    std::string loc = "";
    std::string route = "";
};

#endif // SONG_H

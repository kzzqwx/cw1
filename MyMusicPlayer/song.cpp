#include "song.h"

//it is possible that route is unnecessary

Song::Song()
{

}

std::string Song::getName(){
    return name;
}

std::string Song::getLoc(){
    return loc;
}

//std::string Song::getRoute(){
//    return route;
//}

void Song::setName(std::string name){
    this->name = name;
}

void Song::setLoc(std::string loc){
    this->loc = loc;
}

//void Song::setRoute(std::string route){
//    this->route = route;
//}

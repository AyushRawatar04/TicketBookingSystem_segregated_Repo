#include "Cinema.h"

using namespace std;

Cinema::Cinema(string cinemaName) {
    this->cinemaName = cinemaName;
    addScreens();
}

void Cinema::addScreens() {
    Screen screen1(1, 5, 5, 5);
    Screen screen2(2, 6, 6, 6);
    screens.push_back(screen1);
    screens.push_back(screen2);
}

Screen* Cinema::getScreen(int screenId) {
    for(auto &screen: screens){
        if(screen.getScreenNumber() == screenId){
            return &screen;
        }
    }
    return nullptr;
}

int Cinema::screenCount() {
    return screens.size();
}

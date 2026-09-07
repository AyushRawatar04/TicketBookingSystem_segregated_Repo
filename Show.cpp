#include "Show.h"
#include "Movie.h"
#include "Screen.h"
#include "Seat.h"
#include <iostream>

using namespace std;

void Show::setShow(int startTime, Screen* screen, Movie* movie) {
    this->startTime = startTime;
    this->endTime = startTime + movie->getDuration();
    this->showScreen = screen;
    this->movie = movie;

    vector<Seat>& seats = screen->getSeats();

    for(auto &seat : seats){
        showSeats.push_back(ShowSeat(&seat));
    }
}

vector<ShowSeat>& Show::getShowSeats() {
    return showSeats;
}

int Show::getScreenId() {
    return showScreen->getScreenNumber();
}

int Show::getEndTime() {
    return endTime;
}

int Show::getStartTime() {
    return startTime;
}

string Show::getMovieName() {
    return movie->getTitle();
}

void Show::getScreenInfo() {
    showScreen->displayHallInfo();
}

bool Show::checkAvailability(vector<int>& seatNumbers) {
    for(int seatId : seatNumbers){
        for(ShowSeat &showSeat : showSeats){
            if(showSeat.getId() == seatId){
                if(showSeat.getStatus() != "Available"){
                    cout << "---------Seat is already Booked , your booking has been cancelled------" << endl;
                    return false;
                }
            }
        }
    }
    return true;
}

bool Show::checkValid(vector<int>& seatNumbers) {
    int totalSeats = showScreen->getTotalSeats();
    for(auto val : seatNumbers){
        if(val > totalSeats || val<=0){
            cout << "-------Selected Seat is invalid, your booking has been cancelled-------" << endl;
            return false;
        }
    }
    return true;
}

bool Show::bookSeat(vector<int>& seatNumbers) {
    for(int seatId : seatNumbers){
        for(ShowSeat &showSeat : showSeats){
            if(showSeat.getId() == seatId){
                showSeat.setStatus("Booked");
            }
        }
    }    
    return true;
}

void Show::displaySection(string type) {
    cout << "      " << type << "\n\n";
    for(ShowSeat &showSeat : showSeats){
        if(showSeat.getSeat()->getType() != type){
            continue;
        }
        if(showSeat.getStatus() == "Available"){
            cout << "[" << showSeat.getSeat()->getSeatNumber() << "] ";
        }
        else{
            cout << "[XX] ";
        }
    }
    cout << "\n\n";
}

void Show::displaySeats() {
    cout << "\n";
    cout << "              SCREEN\n";
    cout << "    =============================\n\n";

    displaySection("Silver");
    displaySection("Gold");
    displaySection("Platinum");

    cout << "[01] Available    [XX] Booked\n" <<endl<<endl;
}

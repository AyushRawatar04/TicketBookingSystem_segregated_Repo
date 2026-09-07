#include "BookingService.h"
#include "Cinema.h"
#include "Customer.h"
#include "Movie.h"
#include "Screen.h"
#include "Show.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  Cinema PVR("Pacific");
  Movie movie1("Interstellar", "English", 3);
  Movie movie2("Swapped", "English", 2);
  Movie movie3("Inception", "English", 3);
  Screen *screen1 = PVR.getScreen(1);
  Screen *screen2 = PVR.getScreen(2);
  vector<Show> allShows;
  Show show1, show2, show3,show4;
  show1.setShow(9, screen1, &movie1);
  show2.setShow(10, screen2, &movie2);
  show3.setShow(2, screen1, &movie3);
  show4.setShow(1,screen2,&movie2);

  allShows.push_back(show1);
  allShows.push_back(show2);
  allShows.push_back(show3);
  allShows.push_back(show4);

  BookingService orchestrator;
  orchestrator.initializeSystem(&PVR, allShows);
  Customer user("CB04", 9084748787, &orchestrator);
  while (true) {
    cout << "Enter your choice" << endl;
    cout << "1. Movies" << endl;
    cout << "2. Cancel Booking" << endl;
    cout << "3. My tickets" << endl;
    cout << "4. Exit" << endl;
    int ch = 0;
    cin >> ch;
    switch (ch) {
    case 1: {
      user.browseAndBookMovies(&user);
      break;
    }
    case 2:
      cout<<"Enter Booking Id to cancel Booking"<<endl;
      int bookingId;
      cin>>bookingId;
      if(user.cancelMyBooking(bookingId)==-1){
        cout<<"Booking already Cancelled"<<endl;
      }
      else if(user.cancelMyBooking(bookingId)==0){
        cout<<"Not a valid Booking ID"<<endl;
      }
      else{
        cout<<"Booking cancelled successfully"<<endl;
      }
      break;
    case 3:
      user.printMyTicket();
      break;
    case 4:
      cout << "Exiting" << endl;
      exit(0);
      break;
    default:
      break;
    }
  }
}

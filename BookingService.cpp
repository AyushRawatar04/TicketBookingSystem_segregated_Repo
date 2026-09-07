#include "BookingService.h"
#include "Cinema.h"
#include "Customer.h"
#include "Payment.h"
#include "PriceCalculator.h"
#include "TicketPrinter.h"
#include <iostream>

using namespace std;

void BookingService::initializeSystem(Cinema *PVR, vector<Show> shows) {
  this->PVR = PVR;
  allShows = shows;
}

void BookingService::printCustomerTicket(Customer *customer) {
  TicketPrinter printer;
  printer.printTicket(customer, systemBookings);
}

bool BookingService::payForSeats(int amount) {
  cout << " Which method would you like to Pay " << endl;
  cout << "1. UPI" << endl;
  cout << "2. Card" << endl;
  cout << "3. Cash" << endl;

  int paymentMethod = 0;
  cin >> paymentMethod;
  Payment *payment = nullptr;
  switch (paymentMethod) {
  case 1: {
    payment = new UPI();
    payment->pay(amount);
    break;
  }
  case 2: {
    payment = new CreditCard();
    payment->pay(amount);
    break;
  }
  case 3: {
    payment = new CashPayment();
    payment->pay(amount);
    break;
  }
  default: {
    return false;
    break;
  }
  }
  delete payment;
  return true;
}

void BookingService::bookShowSeats(Show *selectedShow, Customer *customer) {
  cout << "  ------Book seats-----  " << endl;

  cout << "  Enter the count of seats to book " << endl;
  int cntOfSeats = 0;
  cin >> cntOfSeats;
  vector<int> seatsToBook(cntOfSeats);
  for (int i = 0; i < cntOfSeats; i++) {
    cout << "  Enter seat number that is to be booked" << endl;
    cin >> seatsToBook[i];
  }

  if (selectedShow->checkValid(seatsToBook) &&
      selectedShow->checkAvailability(seatsToBook)) {
    PriceCalculator price;
    int bookingPrice =
        price.calculate(seatsToBook, selectedShow->getShowSeats());
    cout << " ------- Total Amount = " << bookingPrice << " -------  " << endl;
    if (payForSeats(bookingPrice)) {
      Booking booking(selectedShow, true, seatsToBook, bookingPrice,
                      customer->getCustId());
      systemBookings.push_back(booking);
      selectedShow->bookSeat(seatsToBook);
    } else {
      Booking booking(selectedShow, false, seatsToBook, bookingPrice,
                      customer->getCustId());
      systemBookings.push_back(booking);
    }
  }
}

void BookingService::select_Show_For_The_Movie(int choice, string movie,Customer *customer) {
  int sNo = 1;
  Show *selectedShow = nullptr;
  for (int i = 0; i < allShows.size(); i++) {
    if (allShows[i].getMovieName() == movie) {
      if (choice == sNo) {
        selectedShow = &allShows[i];
        selectedShow->displaySeats();
        break;
      }
      sNo++;
    }
  }
  if (selectedShow) {
    bookShowSeats(selectedShow, customer);
  }
  return;
}

void BookingService::find_All_Show_For_Selected_Movie(string &movie,Customer *customer) {
  cout << endl << "Movie = " << movie << endl <<endl;
  int sNo = 1;
  for (int i = 0; i < allShows.size(); i++) {
    if (allShows[i].getMovieName() == movie) {
      cout << "[" << sNo << "]" << " Screen=" << allShows[i].getScreenId()
           << "     start time=" << allShows[i].getStartTime()
           << "     end time=" << allShows[i].getEndTime()<<endl;
      sNo++;
    }
  }
  cout << endl << endl;
  cout << "     Choose a Show" << endl;
  int choice;
  cin >> choice;
  select_Show_For_The_Movie(choice, movie, customer);
}

void BookingService::selectMovie(int movieChoice, Customer *customer) {
  switch (movieChoice) {
  case 1: {
    string movie = "Interstellar";
    find_All_Show_For_Selected_Movie(movie, customer);
    break;
  }
  case 2: {
    string movie = "Swapped";
    find_All_Show_For_Selected_Movie(movie, customer);
    break;
  }
  case 3: {
    string movie = "Inception";
    find_All_Show_For_Selected_Movie(movie, customer);
    break;
  }
  default: {
    cout << "********--Wrong input--********" << endl;
    break;
  }
  }
}

void BookingService::displayMovies(Customer *customer) {
  cout << "--------Select a movie--------" << endl;
  cout << "1. Interstellar" << endl;
  cout << "2. Swapped" << endl;
  cout << "3. Inception" << endl;
  cout << endl;

  int movieChoice = 0;
  cin >> movieChoice;
  selectMovie(movieChoice, customer);
}

int BookingService::CancelBooking(int bookingId){
  int flag=0;
  for(Booking &booking: systemBookings){
    if(booking.getBookingId()==bookingId ){
      flag=1;
      if(booking.getBookingStatus()==false){
        return -1;
      }
      vector<ShowSeat>&showSeats=booking.getShow()->getShowSeats();
      for(int seatId:booking.getSeatIds()){
        for(ShowSeat &showSeat:showSeats){
          if(showSeat.getId()==seatId){
            showSeat.setStatus("Available");
          }
        }
      }
      booking.setBookingStatus(false);
    }
  }
  if(flag==1)
  return 1;
  else
  return 0;
}
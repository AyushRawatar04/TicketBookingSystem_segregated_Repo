#ifndef BOOKINGSERVICE_H
#define BOOKINGSERVICE_H

#include <vector>
#include <string>
#include "Show.h"
#include "Booking.h"

class Cinema;
class Customer;

class BookingService {
private:
    Cinema *PVR;
    std::vector<Show> allShows;
    std::vector<Booking> systemBookings;
public:
    void initializeSystem(Cinema *PVR, std::vector<Show> shows);
    void printCustomerTicket(Customer *customer);
    bool payForSeats(int amount);
    void bookShowSeats(Show* selectedShow, Customer *customer);
    void select_Show_For_The_Movie(int choice, std::string movie, Customer *customer);
    void find_All_Show_For_Selected_Movie(std::string &movie, Customer *customer);
    void selectMovie(int movieChoice, Customer *customer);
    void displayMovies(Customer *customer);
    int CancelBooking(int bookingId);
};

#endif

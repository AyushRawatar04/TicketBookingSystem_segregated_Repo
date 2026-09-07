#include "TicketPrinter.h"
#include "Customer.h"
#include "Show.h"
#include <iostream>

using namespace std;

void TicketPrinter::printTicket(Customer *customer, vector<Booking>& systemBookings) {
    bool hasTickets = false;
    for (auto& booking : systemBookings) {
        if (booking.getCustomerId() == customer->getCustId()) {
            hasTickets = true;
            
            cout << "================== TICKET ==================" << endl;
            cout << "Booking ID : BK" << booking.getBookingId() << endl; 
            cout << "Movie      : " << booking.getShow()->getMovieName() << endl;
            cout << "Screen     : Screen-" << booking.getShow()->getScreenId() 
                 << "    " << booking.getShow()->getStartTime() << ":00" << endl;
            
            cout << "Seats      : ";
            vector<int> seats = booking.getSeatIds();
            for (size_t i = 0; i < seats.size(); i++) {
                cout << seats[i];
                if (i != seats.size() - 1) {
                    cout << ", ";
                }
            }
            cout << endl;

            cout << "Amount     : Rs." << booking.getTotalAmount() 
                 << "        Status: " << (booking.getBookingStatus() ? "CONFIRMED" : "FAILED") << endl;
                 
            cout << "============================================" << endl << endl;
        }
    }

    if (!hasTickets) {
        cout << "No booking history found for this account." << endl;
    }
}

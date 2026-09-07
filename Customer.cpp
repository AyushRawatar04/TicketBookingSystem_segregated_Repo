#include "Customer.h"
#include "BookingService.h"

using namespace std;

int Customer::nextCustId = 11;

Customer::Customer(string name, long long phoneNo, BookingService *bookingService) {
    this->name = name;
    this->phoneNo = phoneNo;
    this->bookingService = bookingService;
    this->custId = nextCustId;
    nextCustId++;
}

int Customer::cancelMyBooking(int bookingId){
    return bookingService->CancelBooking(bookingId);
}
void Customer::printMyTicket(){
    bookingService->printCustomerTicket(this);
}
int Customer::getCustId() {
    return custId;
}

void Customer::browseAndBookMovies(Customer *customer) {
    bookingService->displayMovies(customer);
}

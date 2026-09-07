#include "Payment.h"
#include <iostream>

using namespace std;

void UPI::pay(int amount) {
    cout << "Payment from UPI of Rs." << amount << " successful" << endl;
}

void CreditCard::pay(int amount) {
    cout << "Payment from credit card of Rs." << amount << " successful" << endl;
}

void CashPayment::pay(int amount) {
    cout << "payment from cashpayment of Rs." << amount << " successful" << endl;
}

# Ticket Booking System

A console-based Cinema Ticket Booking System developed in C++ using Object-Oriented Programming principles.

The system allows customers to browse movies, select shows, check seat availability, book seats, make payments, print tickets, and cancel bookings.

## Features

- View available movies
- View shows for a selected movie
- Display seat availability
- Select and book seats
- Calculate ticket price based on seat type
- Multiple payment options:
  - UPI
  - Credit Card
  - Cash
- Confirm booking after successful payment
- Print booking tickets
- Cancel existing bookings
- Release seats after cancellation or failed payment
- Generate unique Customer IDs and Booking IDs

## Seat Pricing

| Seat Type | Price |
|-----------|-------|
| Silver | ₹150 |
| Gold | ₹250 |
| Platinum | ₹400 |

## Classes

- **Movie** — Stores movie details such as title, language, and duration.
- **Seat** — Represents a physical seat and its type.
- **ShowSeat** — Maintains the status of a seat for a particular show.
- **Screen** — Manages the seats available in a screen.
- **Cinema** — Manages the screens in the cinema.
- **Show** — Represents a movie show and manages its show seats.
- **Customer** — Stores customer information and handles customer operations.
- **Booking** — Stores booking details and booking status.
- **BookingService** — Handles the main booking workflow.
- **PriceCalculator** — Calculates the total booking amount.
- **Payment** — Abstract class defining the payment interface.
- **UPI** — Implements payment through UPI.
- **CreditCard** — Implements payment through credit card.
- **CashPayment** — Implements payment through cash.
- **TicketPrinter** — Prints ticket details.

## OOP Concepts Used

- **Encapsulation** — Data members are kept private and accessed through public methods.
- **Inheritance** — UPI, CreditCard, and CashPayment inherit from the Payment class.
- **Polymorphism** — Different payment classes implement the `pay()` function.
- **Composition** — Cinema contains Screens, Screen contains Seats, Show contains ShowSeats, and BookingService contains Bookings.
- **Association** — Classes interact with each other through pointers and references.

## Requirements

- C++ compiler with C++17 support
- GCC / G++

## How to Run

Open the terminal in the project directory and compile all the `.cpp` files:

```bash
g++ -std=c++17 *.cpp -o TicketBookingSystem
./TicketBookingSystem
```

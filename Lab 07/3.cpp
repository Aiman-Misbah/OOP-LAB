#include <iostream>
#include <string>
using namespace std;

class Ticket
{
protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(int id, string name, double p, string d, string dest)
        : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}

    virtual void reserve()
    {
        cout << "Ticket reserved for " << passengerName << endl;
    }

    virtual void cancel()
    {
        cout << "Ticket canceled for " << passengerName << endl;
    }

    virtual void displayTicketInfo() const
    {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger: " << passengerName << endl;
        cout << "Price: $" << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
    }

    virtual ~Ticket() {}
};

class FlightTicket : public Ticket
{
private:
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, double p, string d, string dest, string airline, string flightNo, string sClass)
        : Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flightNo), seatClass(sClass) {}

    void displayTicketInfo() const override
    {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Seat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket
{
private:
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, double p, string d, string dest, string trainNo, string coach, string time)
        : Ticket(id, name, p, d, dest), trainNumber(trainNo), coachType(coach), departureTime(time) {}

    void reserve() override
    {
        cout << "Train ticket reserved for " << passengerName << " in " << coachType << " coach." << endl;
    }
};

class BusTicket : public Ticket
{
private:
    string busCompany;
    int seatNumber;

public:
    BusTicket(int id, string name, double p, string d, string dest, string company, int seat)
        : Ticket(id, name, p, d, dest), busCompany(company), seatNumber(seat) {}

    void cancel() override
    {
        cout << "Bus ticket for " << passengerName << " has been canceled. Refund processed." << endl;
    }
};

class ConcertTicket : public Ticket
{
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double p, string d, string dest, string artist, string v, string sType)
        : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(sType) {}

    void displayTicketInfo() const override
    {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main()
{
    FlightTicket flight1(101, "Ahmed Khan", 500.0, "2025-05-10", "New York", "AirBlue", "AB123", "Business");
    TrainTicket train1(202, "Sara Ali", 150.0, "2025-06-01", "Lahore", "PK Express", "Economy", "09:00 AM");
    BusTicket bus1(303, "Usman Raza", 50.0, "2025-04-20", "Islamabad", "GreenLine", 12);
    ConcertTicket concert1(404, "Aisha Malik", 75.0, "2025-07-15", "Dubai", "Atif Aslam", "Coca-Cola Arena", "VIP");

    flight1.displayTicketInfo();
    cout << endl;
    train1.reserve();
    cout << endl;
    bus1.cancel();
    cout << endl;
    concert1.displayTicketInfo();
    cout << endl;
    return 0;
}


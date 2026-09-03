#include <iostream>
#include <string>

using namespace std;

//USER CLASS


class User
{
private:
    // ACCESS SPECIFIER: PRIVATE
    int userId;

protected:
    // ACCESS SPECIFIER: PROTECTED
    string name;
    string email;

public:
    // DEFAULT CONSTRUCTOR
    User()
    {
        userId = 0;
        name = "Unknown";
        email = "Not Provided";
    }

    // PARAMETERIZED CONSTRUCTOR
    User(int id, string n, string e)
    {
        userId = id;
        name = n;
        email = e;
    }

    // PUBLIC METHOD
    void login()
    {
        cout << name << " logged in successfully." << endl;
    }

    // GETTERS
    int getUserId()
    {
        return userId;
    }

    string getName()
    {
        return name;
    }

    string getEmail()
    {
        return email;
    }
};

// Service Class
class Service
{
private:
    int serviceId;
    string name;
    string description;
    double price;

public:

    // DEFAULT CONSTRUCTOR
    Service()
    {
        serviceId = 0;
        name = "Unknown";
        description = "Not Available";
        price = 0;
    }

    // PARAMETERIZED CONSTRUCTOR
    Service(int id, string n, string d, double p)
    {
        serviceId = id;
        name = n;
        description = d;
        price = p;
    }

    string getName()
    {
        return name;
    }

    string getDescription()
    {
        return description;
    }

    double getPrice()
    {
        return price;
    }

    int getServiceId()
    {
        return serviceId;
    }

    void getDetails()
    {
        cout << "Service ID: " << serviceId << endl;
        cout << "Service: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Price: Rs. " << price << endl;
    }
};

// TimeSlot class
class TimeSlot
{
private:
    int slotId;
    string date;
    string time;
    bool available;

public:

    // DEFAULT CONSTRUCTOR
    TimeSlot()
    {
        slotId = 0;
        date = "Not Set";
        time = "Not Set";
        available = true;
    }

    // PARAMETERIZED CONSTRUCTOR
    TimeSlot(int id, string d, string t, bool a)
    {
        slotId = id;
        date = d;
        time = t;
        available = a;
    }

    bool checkAvailability()
    {
        return available;
    }

    void reserve()
    {
        if (available)
        {
            available = false;
            cout << "Time slot reserved successfully." << endl;
        }
        else
        {
            cout << "Time slot is already unavailable." << endl;
        }
    }

    string getDate()
    {
        return date;
    }

    string getTime()
    {
        return time;
    }

    int getSlotId()
    {
        return slotId;
    }
};
///                      BOOKING CLASS
class Booking
{
private:
    int bookingId;
    string status;
    int serviceId;
    int slotId;

public:

    // DEFAULT CONSTRUCTOR
    Booking()
    {
        bookingId = 0;
        status = "Pending";
        serviceId = 0;
        slotId = 0;
    }

    // PARAMETERIZED CONSTRUCTOR
    Booking(int id, string s, int sid, int tid)
    {
        bookingId = id;
        status = s;
        serviceId = sid;
        slotId = tid;
    }

    void createBooking()
    {
        cout << "Booking " << bookingId
             << " created." << endl;
    }

    void confirmBooking()
    {
        status = "Confirmed";

        cout << "Booking " << bookingId
             << " confirmed." << endl;
    }

    void rejectBooking()
    {
        status = "Rejected";

        cout << "Booking " << bookingId
             << " rejected." << endl;
    }

    void completeBooking()
    {
        status = "Completed";

        cout << "Booking " << bookingId
             << " completed." << endl;
    }

    void updateStatus(string s)
    {
        status = s;

        cout << "Booking " << bookingId
             << " status updated to "
             << status << endl;
    }

    int getBookingId()
    {
        return bookingId;
    }

    string getStatus()
    {
        return status;
    }

    // OPERATOR OVERLOADING

bool operator==(const Booking& other)
    {
        return bookingId == other.bookingId;
    }
};

//                     CUSTOMER CLASS INHERITANCE

class Customer : public User
{
private:
    string phone;

public:

    // DEFAULT CONSTRUCTOR
    Customer() : User()
    {
        phone = "Not Provided";
    }

    // PARAMETERIZED CONSTRUCTOR
    Customer(
        int id,
        string n,
        string e,
        string p
    ) : User(id, n, e)
    {
        phone = p;
    }

    void viewServices()
    {
        cout << name
             << " is viewing available services."
             << endl;
    }

    void selectService(Service service)
    {
        cout << name
             << " selected service: "
             << service.getName()
             << endl;
    }



    // METHOD OVERLOADING
  

    // bookService() WITHOUT TimeSlot
    void bookService(Service service)
    {
        cout << name
             << " booked service: "
             << service.getName()
             << endl;

        cout << "Price: Rs. "
             << service.getPrice()
             << endl;
    }


    // bookService() WITH TimeSlot
    void bookService(Service service, TimeSlot slot)
    {
        cout << name
             << " booked service: "
             << service.getName()
             << endl;

        cout << "Price: Rs. "
             << service.getPrice()
             << endl;

        cout << "Date: "
             << slot.getDate()
             << endl;

        cout << "Time: "
             << slot.getTime()
             << endl;
    }


    void makePayment(double amount)
    {
        cout << name
             << " made payment of Rs. "
             << amount
             << endl;
    }

    void viewBooking(Booking booking)
    {
        cout << "Booking ID: "
             << booking.getBookingId()
             << endl;

        cout << "Status: "
             << booking.getStatus()
             << endl;
    }

    void cancelBooking(Booking booking)
    {
        cout << "Booking "
             << booking.getBookingId()
             << " cancelled."
             << endl;
    }

    void giveFeedback(string feedback)
    {
        cout << "Feedback from "
             << name
             << ": "
             << feedback
             << endl;
    }
};
// ============================================================
//                  SERVICE PROVIDER CLASS
//                       INHERITANCE
// ============================================================

class ServiceProvider : public User
{
private:
    string phone;
    bool available;

public:

    // DEFAULT CONSTRUCTOR
    ServiceProvider() : User()
    {
        phone = "Not Provided";
        available = true;
    }

    // PARAMETERIZED CONSTRUCTOR
    ServiceProvider(
        int id,
        string n,
        string e,
        string p,
        bool a
    ) : User(id, n, e)
    {
        phone = p;
        available = a;
    }

    void viewBookings()
    {
        cout << name
             << " is viewing bookings."
             << endl;
    }

    void acceptBooking(Booking& booking)
    {
        booking.confirmBooking();

        cout << name
             << " accepted booking "
             << booking.getBookingId()
             << endl;
    }

    void rejectBooking(Booking& booking)
    {
        booking.rejectBooking();

        cout << name
             << " rejected booking "
             << booking.getBookingId()
             << endl;
    }

    void performService(Booking& booking)
    {
        cout << name
             << " is performing booking "
             << booking.getBookingId()
             << endl;

        booking.completeBooking();
    }

    void updateBookingStatus(
        Booking& booking,
        string status
    )
    {
        booking.updateStatus(status);
    }
};


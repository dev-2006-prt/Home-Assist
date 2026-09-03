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



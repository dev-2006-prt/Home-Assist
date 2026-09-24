#include <iostream>
#include <string>

using namespace std;

// USER CLASS

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
        this->userId = 0;
        this->name = "Unknown";
        this->email = "Not Provided";
    }

    // PARAMETERIZED CONSTRUCTOR
    User(int id, string n, string e)
    {
        this->userId = id;
        this->name = n;
        this->email = e;
    }

    // PUBLIC METHOD
   virtual void login()
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


// SERVICE CLASS

class Service
{
private:
    int serviceId;
    string name;
    string description;
    double price;
static int serviceCount ;

public:

    static void showServiceCount()
    {
        cout << "Total Services: " << serviceCount << endl;
    }


public:
// NESTED CLASS
class Booking
{
private:
    int bookingId;
    string customerName;
    string bookingDate;
    string status;

public:

    // CONSTRUCTOR
    Booking(int id, string customer, string date)
    {
        bookingId = id;
        customerName = customer;
        bookingDate = date;
        status = "Pending";
    }

    // ACCEPT BOOKING
    void acceptBooking()
    {
        status = "Accepted";
        cout << "Booking accepted." << endl;
    }

    // CANCEL BOOKING
    void cancelBooking()
    {
        status = "Cancelled";
        cout << "Booking cancelled." << endl;
    }

    // DISPLAY BOOKING
    void displayBooking()
    {
        cout << "Booking ID: " << bookingId << endl;
        cout << "Customer: " << customerName << endl;
        cout << "Date: " << bookingDate << endl;
        cout << "Status: " << status << endl;
    }
};

    // DEFAULT CONSTRUCTOR
    Service()
    {
        serviceId = 0;
        name = "Unknown";
        description = "Not Available";
        price = 0;
        serviceCount++ ;
    }

    // PARAMETERIZED CONSTRUCTOR
    Service(int id, string n, string d, double p)
    {
        serviceId = id;
        name = n;
        description = d;
        price = p;
        serviceCount++ ;
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

    // FRIEND FUNCTION FOR OPERATOR OVERLOADING
    friend double operator+(Service s1, Service s2)
    {
        return s1.price + s2.price;
    }
};

// DEFINE STATIC VARIABLE
int Service::serviceCount = 0;

// SERVICE PROVIDER CLASS
// ServiceProvider inherits from User

class ServiceProvider : public User
{
private:
    int serviceProviderId;
    string serviceType;
    double rating;

public:

    // DEFAULT CONSTRUCTOR
    ServiceProvider()
    {
        serviceProviderId = 0;
        serviceType = "Not Assigned";
        rating = 0.0;
    }

    // PARAMETERIZED CONSTRUCTOR
    ServiceProvider(int spId, string n, string e,
                    int id, string type, double r)
        : User(id, n, e)
    {
        serviceProviderId = spId;
        serviceType = type;
        rating = r;
    }

    // METHOD
    void login() override
    {
        cout << name
             << " logged in as Service Provider." << endl;
    }
    void provideService()
    {
        cout << name << " provides " << serviceType << " service." << endl;
    }

    // METHOD
    void displayProvider()
    {
        cout << "Service Provider ID: " << serviceProviderId << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Service Type: " << serviceType << endl;
        cout << "Rating: " << rating << endl;
    }
};
class Admin final
{
private:
    int adminId;
    string adminName;
    string email;

public:

    // DEFAULT CONSTRUCTOR
    Admin()
    {
        adminId = 0;
        adminName = "Unknown";
        email = "Not Provided";
    }

    // PARAMETERIZED CONSTRUCTOR
    Admin(int id, string name, string e)
    {
        adminId = id;
        adminName = name;
        email = e;
    }

    // ADMIN LOGIN
    void login()
    {
        cout << adminName
             << " logged in as Admin." << endl;
    }

    // ADD SERVICE
    void addService(Service s)
    {
        cout << "Admin added service: "
             << s.getName() << endl;
    }

    // REMOVE SERVICE
    void removeService(Service s)
    {
        cout << "Admin removed service: "
             << s.getName() << endl;
    }

    // DISPLAY ADMIN DETAILS
    void displayAdmin()
    {
        cout << "Admin ID: " << adminId << endl;
        cout << "Admin Name: " << adminName << endl;
        cout << "Email: " << email << endl;
    }
};


int main()
{
    // Creating User using DEFAULT CONSTRUCTOR
    User user1;

    cout << "---- Default User ----" << endl;
    cout << "User ID: " << user1.getUserId() << endl;
    cout << "Name: " << user1.getName() << endl;
    cout << "Email: " << user1.getEmail() << endl;

    user1.login();

    cout << endl;


    // Creating User using PARAMETERIZED CONSTRUCTOR
    User user2(101, "Devansh", "devansh@gmail.com");

    cout << "---- Parameterized User ----" << endl;
    cout << "User ID: " << user2.getUserId() << endl;
    cout << "Name: " << user2.getName() << endl;
    cout << "Email: " << user2.getEmail() << endl;

    user2.login();

    cout << endl;


    // Creating Service using DEFAULT CONSTRUCTOR
    Service service1;

    cout << "---- Default Service ----" << endl;
    service1.getDetails();

    cout << endl;


    // Creating Service using PARAMETERIZED CONSTRUCTOR
    Service service2(
        201,
        "AC Repair",
        "Air conditioner repair and servicing",
        799
    );

    cout << "---- Parameterized Service ----" << endl;
    service2.getDetails();

    cout << endl;


    // Creating another service
    Service service3(
        202,
        "Plumbing",
        "Home plumbing and repair",
        500
    );

    cout << "---- Second Service ----" << endl;
    service3.getDetails();

    cout << endl;

    cout << "----- STATIC FUNCTION -----" << endl; 
    Service::showServiceCount(); cout << endl;


    // OPERATOR OVERLOADING
    double total = service2 + service3;

    cout << "---- Operator Overloading ----" << endl;
    cout << "Price of Service 2: Rs. " << service2.getPrice() << endl;
    cout << "Price of Service 3: Rs. " << service3.getPrice() << endl;
    cout << "Total Price: Rs. " << total << endl;
    cout << endl ;
    cout << "----Service Provider ----" << endl;
    ServiceProvider sp(
        501,
        "Rahul",
        "rahul@gmail.com",
        101,
        "Plumbing",
        4.5
    );

    sp.login();             // inherited from User
    sp.displayProvider();   // ServiceProvider's own method
    sp.provideService();

    // ------------------------------------
    // OBJECT SLICING
    // ------------------------------------

    cout << "---- Object Slicing ----" << endl;

    User user3 = sp;

    cout << "User ID: "
         << user3.getUserId() << endl;

    cout << "Name: "
         << user3.getName() << endl;

    cout << "Email: "
         << user3.getEmail() << endl;

    user3.login();

    cout << endl;

cout << "---- Final Class ----" << endl;

Admin admin(
    9001,
    "System Admin",
    "admin@homeservice.com"
);

admin.displayAdmin();

admin.login();

admin.addService(service2);

admin.removeService(service3);

cout << "---- Nested Class: Booking ----" << endl;

Service::Booking booking(
    1001,
    "Devansh",
    "18 September 2026"
);

booking.displayBooking();

cout << endl;

booking.acceptBooking();

cout << endl;

booking.displayBooking();

    return 0;
}

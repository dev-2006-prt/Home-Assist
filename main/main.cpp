#include <iostream>
#include <string>
#include <thread>
#include <mutex>

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

public :
// BASIC-TO-CLASS CONVERSION
Service(double p)
{
    serviceId = 0;
    name = "Custom Service";
    description = "Created by conversion";
    price = p;
    serviceCount++;
}

operator double()
{
    return price;
}

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

    int getBookingId(){
        return bookingId ;
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
        if (p <= 0)
        throw invalid_argument("Price must be positive");

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

class Payment
{
private:
    int paymentId;
    int bookingId;
    double amount;
    string method;
    string status;

public:
    Payment()
    {
        paymentId = 0;
        bookingId = 0;
        amount = 0;
        method = "Not Selected";
        status = "Pending";
    }

    Payment(int pId, int bId, double amt, string m)
    {
        if (amt <= 0)
            throw invalid_argument("Payment amount must be positive");

        paymentId = pId;
        bookingId = bId;
        amount = amt;
        method = m;
        status = "Pending";
    }

    void processPayment()
    {
        if (status == "Paid")
        {
            cout << "Payment already completed." << endl;
            return;
        }
        status = "Paid";
        cout << "Payment of Rs. " << amount
             << " successful via " << method << "." << endl;
    }

    void refundPayment()
    {
        if (status != "Paid")
        {
            cout << "Refund not possible. Payment is not completed." << endl;
            return;
        }
        status = "Refunded";
        cout << "Rs. " << amount << " refunded." << endl;
    }

    void displayPayment()
    {
        cout << "Payment ID: " << paymentId << endl;
        cout << "Booking ID: " << bookingId << endl;
        cout << "Amount: Rs. " << amount << endl;
        cout << "Method: " << method << endl;
        cout << "Status: " << status << endl;
    }
};

class ServiceProvider : virtual public User
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
class Admin : virtual public User 
{
private:
    int adminId;

public:

    // DEFAULT CONSTRUCTOR
    Admin()
    {
        adminId = 0;
    }

    // PARAMETERIZED CONSTRUCTOR
    Admin(int id, string name, string e)
    : User(id, name, e)
    {
        adminId = id;
    }

    // ADMIN LOGIN
    void login() override
    {
        cout << name
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
        cout << "Admin Name: " << name << endl;
        cout << "Email: " << email << endl;
    }
};
class Manager : public ServiceProvider, public Admin
{
public:

    Manager(int spId,
            string n,
            string e,
            int id,
            string type,
            double r)
        : User(id, n, e),
          ServiceProvider(spId, n, e, id, type, r),
          Admin(id, n, e)
    {
    }

    void displayManager()
    {
        cout << "Manager Name: "
             << name << endl;

        cout << "Email: "
             << email << endl;
    }

    void login() override
    {
        cout << name
             << " logged in as Manager."
             << endl;
    }

    
};
// FUNCTION TEMPLATE
template <class T>
void displayValue(T value)
{
    cout << value << endl;
}

class ServiceInfo
{
public:
    int price;

    ServiceInfo(int p)
    {
        price = p;
    }
};

class PaymentInfo
{
public:
    int amount;

    // Class-to-class conversion constructor
    PaymentInfo(ServiceInfo s)
    {
        amount = s.price;
    }

    void display()
    {
        cout << "Payment Amount: Rs. "
             << amount << endl;
    }
};

// FEEDBACK CLASS (Use case: Feed back)
class Feedback
{
private:
    int feedbackId;
    string customerName;
    string serviceName;
    int rating;
    string comment;

public:
    Feedback()
    {
        feedbackId = 0;
        customerName = "Unknown";
        serviceName = "Not Specified";
        rating = 0;
        comment = "No comment";
    }

    Feedback(int id, string customer, string service, int r, string c)
    {
        if (r < 1 || r > 5)
            throw invalid_argument("Rating must be between 1 and 5");

        feedbackId = id;
        customerName = customer;
        serviceName = service;
        rating = r;
        comment = c;
    }

    void displayFeedback()
    {
        cout << "Feedback ID: " << feedbackId << endl;
        cout << "Customer: " << customerName << endl;
        cout << "Service: " << serviceName << endl;
        cout << "Rating: " << rating << "/5" << endl;
        cout << "Comment: " << comment << endl;
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

    cout << "---- Virtual Function ----" << endl;

    User* userPtr = &sp;

    userPtr->login();

    cout << endl;

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
    cout << "---- Feedback Class ----" << endl;

Feedback feedback(4001, "Devansh", service2.getName(), 5,
                  "Quick and professional service.");

feedback.displayFeedback();

cout << endl;

cout << "---- Pointer to Object ----" << endl;

Service* servicePtr = &service2;

servicePtr->getDetails();

cout << endl;

cout << "---- Pointer to Derived Class ----" << endl;

ServiceProvider* spPtr = &sp;

spPtr->displayProvider();
spPtr->provideService();

cout << endl;

cout << "---- Virtual Base Class ----" << endl;

Manager manager(
    701,
    "Amit",
    "amit@gmail.com",
    301,
    "Electrical",
    4.8
);

manager.displayManager();

cout << endl;

manager.provideService();

cout << endl;

manager.addService(service2);

cout << endl;

manager.login();

cout << "---- Basic-to-Class Casting ----" << endl;

double amount = 650;
Service service4 = amount;

service4.getDetails();

cout << "---- Class-to-Basic Casting ----" << endl;

double amount2 = service2;

cout << "Converted price: Rs. "
     << amount2 << endl;
cout << "---- Templates ----" << endl;

displayValue(service2.getName());
displayValue(service2.getPrice());
displayValue(service2.getServiceId());

cout <<"---- Class-to-Class Typecasting ----" << endl ;

ServiceInfo s(799);

PaymentInfo p = s;

p.display();

    cout << "---- Payment Class ----" << endl;

Payment payment(3001, booking.getBookingId(), service2.getPrice(), "UPI");

payment.displayPayment();
cout << endl;
payment.processPayment();
cout << endl;
payment.displayPayment();

cout << endl;

cout << "---- Try-catch ----" << endl ;
try {
    Service s(999, "Test", "Invalid service", -100);
}
catch (const invalid_argument& e) {
    cout << "Error: " << e.what() << endl;
}

try {
    throw invalid_argument("Invalid booking details");
}
catch (const invalid_argument& e) {
    cout << "Specific exception: " << e.what() << endl;
}
catch (const exception& e) {
    cout << "General exception: " << e.what() << endl;
}
return 0 ;
}

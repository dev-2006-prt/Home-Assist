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


// SERVICE CLASS

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

    // FRIEND FUNCTION FOR OPERATOR OVERLOADING
    friend double operator+(Service s1, Service s2)
    {
        return s1.price + s2.price;
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


    // OPERATOR OVERLOADING
    double total = service2 + service3;

    cout << "---- Operator Overloading ----" << endl;
    cout << "Price of Service 2: Rs. " << service2.getPrice() << endl;
    cout << "Price of Service 3: Rs. " << service3.getPrice() << endl;
    cout << "Total Price: Rs. " << total << endl;

    return 0;
}

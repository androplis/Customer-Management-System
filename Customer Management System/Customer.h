// Andrew Biddle
// CIS 1202.501
// 12.7.20

#include <iostream>
#include <string>
#include <vector>
#include "Service.h"
#include "Payment.h"
using namespace std;

#ifndef Customer_h
#define Customer_h

class Customer {
// Customer class contains basic customer information. Assosiative relationship with service and payment classes
private:
    int customerNum;
    string fullName;
    string address;
    string city;
    string state;
    string zip;
    string email;
    string phone;
    double balance;
    double totPayments;
    int numServices;
    
public:
    // Default Constructor
    Customer() {
        customerNum = 0;
        fullName = "";
        address = "";
        city = "";
        state = "";
        zip = "";
        email = "";
        phone = "";
        balance = 0.0;
        totPayments = 0.0;
        numServices = 0;
    }
    
    // == Accessors ==
    int getCustomerNum()
    { return customerNum; }
    
    string getFullName()
    { return fullName; }

    string getAddress()
    { return address; }
    
    string getCity()
    { return city; }
    
    string getState()
    { return state; }
    
    string getZip()
    { return zip; }
    
    string getEmail()
    { return email; }
    
    string getPhone()
    { return phone; }
    
    double getBalance()
    { return balance; }
    
    double getTotPayments()
    { return totPayments; }
    
    int getNumServices()
    { return numServices; }
    
    // == Mutators ==
    void setCustomerNum(int num)
    { customerNum = num; }
    
    void setFullName(string name)
    { fullName = name; }

    void setAddress(string newAddress)
    { address = newAddress; }
    
    void setCity(string newCity)
    { city = newCity; }
    
    void setState(string newState)
    { state = newState; }
    
    void setZip(string newZip)
    { zip = newZip; }
    
    void setEmail(string address)
    { email = address; }
    
    void setPhone(string number)
    { phone = number; }
    
    void setBalance(double amount)
    { balance = amount; }
    
    void setTotPayments(double amount)
    { totPayments = amount; }
    
    void setNumServices(int number)
    { numServices = number;}
    
    void setValues(int num, string name, string add, string newCity, string newState, string newZip, string eAdd, string number, double amount) {
        customerNum = num;
        fullName = name;
        address = add;
        city = newCity;
        state = newState;
        zip = newZip;
        email = eAdd;
        phone = number;
        balance = amount;
        totPayments = 0.00;
        numServices = 0;
    }
    
    // Overloaded function
    void setVaules(string name, vector<string> fullAddress, string emailAdd, string phoneNum) {
        fullName = name;
        address = fullAddress.at(0);
        city = fullAddress.at(1);
        state = fullAddress.at(2);
        zip = fullAddress.at(3);
        email = emailAdd;
        phone = phoneNum;
        balance = 0.0;
        totPayments = 0.00;
        numServices = 0;
    }

    // Display customer information
    void displayCustomerInfo() {
        cout << endl << "Customer Num: " << customerNum;
        cout << endl << "Customer Name: " << fullName;
        cout << endl << "Address: " << address << " -  " << city << ", " << state << " " << zip;
        cout << endl << "Email: " << email;
        cout << endl << "Phone: " << phone;
        cout << endl << "Balance: $" << balance;
        cout << endl << "Total Payments: $" << totPayments;
        cout << endl << "Number of Services: " << numServices;
    }
    
    // Adds service to service history and increases balance
    void performService(Service serviceItem) {
        balance += serviceItem.getPrice();
        numServices++;
    }
    
    // Adds payment to payment history and deducts amount from balance
    void makePayment(Payment paymentItem) {
        balance -= paymentItem.getAmount();
        totPayments += paymentItem.getAmount();
    }
};

#endif /* Customer_h */

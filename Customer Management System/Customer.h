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
    vector<Service> serviceHistory;
    vector<Payment> paymentHistory;
    
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
    }
    
    // Displays the customer's service history
    void displayServiceHistory() {
        for(int i = 0; i < serviceHistory.size(); i++) {
            serviceHistory.at(i).displayService();
        }
    }
    
    // Displays the customer's payment history
    void displayPaymentHistory() {
        for(int i = 0; i < paymentHistory.size(); i++) {
            paymentHistory.at(i).displayPayment();
        }
    }
    
    // Display customer information
    void displayCustomerInfo() {
        cout << endl << "Customer Num: " << customerNum;
        cout << endl << "Customer Name: " << fullName;
        cout << endl << "Address: " << address << " -  " << city << ", " << state << " " << zip;
        cout << endl << "Email: " << email;
        cout << endl << "Phone: " << phone;
        cout << endl << "Balance: $" << balance;
    }
    
    // Adds service to service history and increases balance
    void performService(Service serviceItem) {
        serviceHistory.push_back(serviceItem);
        balance += serviceItem.getPrice();
    }
    
    // Adds payment to payment history and deducts amount from balance
    void makePayment(Payment paymentItem) {
        paymentHistory.push_back(paymentItem);
        balance -= paymentItem.getAmount();
    }
};

#endif /* Customer_h */

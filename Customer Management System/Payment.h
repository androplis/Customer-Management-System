// Andrew Biddle
// CIS 1202.501
// 12.7.20

#include <iostream>
#include <string>
using namespace std;

#ifndef Payment_h
#define Payment_h

class Payment {
    // Class payment stores information regarding customer payments such as the amount, type and date of the payment.
private:
    int paymentNum;
    string customerName;
    double amount;
    string paymentType;
    string date;

public:
    // Constructor
    Payment() {
        paymentNum = 0;
        customerName = "";
        amount = 0.0;
        paymentType = "";
        date = "";
    }
    
    // Accessors
    int getPaymentNum()
    { return paymentNum; }
    string getCustomerName()
    { return customerName; }
    double getAmount()
    { return amount; }
    string getPaymentType()
    { return paymentType; }
    string getDate()
    { return date; }
    
    // Mutators
    // Note - no mutator for payment num (unique value)
    void setCustomerName(string name)
    { customerName = name; }
    void setPaymentType(string type)
    { paymentType = type; }
    void setAmount(double newAmount)
    { amount = newAmount; }
    void setDate(string newDate)
    { date = newDate; }
    
    // Sets the values of all the fields
    void setValues(int num, string name, double newAmount, string type, string newDate) {
        paymentNum = num;
        customerName = name;
        amount = newAmount;
        paymentType = type;
        date = newDate;
    }
    
    // Displays all the payment information
    void displayPayment() {
        cout << endl << "Payment Num: #" << paymentNum;
        cout << endl << "Customer Name - " << customerName;
        cout << endl << "Amount: $" << amount;
        cout << endl << "Payment Type: " << paymentType;
        cout << endl << "Date: " << date << endl;
    }
};

#endif /* Payment_h */

// Andrew Biddle
// CIS 1202.501
// 12.7.20

#include <iostream>
#include <string>
using namespace std;

#ifndef Service_h
#define Service_h

class Service {
// Service class contains information on the various companies services
private:
    int serviceNum;
    string serviceName;
    string category;
    double price;
    
public:
    // Default Constructor
    Service() {
        serviceNum = 0;
        serviceName = "";
        category = "";
        price = 0.0;
    }
    
    // Accessor Methods
    int getServiceNum()
    { return serviceNum; }
    
    string getServiceName()
    { return serviceName; }
    
    string getCategory()
    { return category; }
    
    int getPrice()
    { return price; }
    
    // Mutator Methods
    void setServiceNum(int num)
    { serviceNum = num; }
    
    void setServiceName(string name)
    { serviceName = name; }
    
    void setCategory(string cat)
    { category = cat; }
    
    void setPrice(double amount)
    { price = amount; }
    
    // Sets the values of all the fiedls
    void setValues(int num, string name, string cat, double amount) {
        serviceNum = num;
        serviceName = name;
        category = cat;
        price = amount;
    }
    
    // Displays all the service information
    void displayService() {
        cout << endl << "Service Num: " << serviceNum;
        cout << endl << "Service Name: " << serviceName;
        cout << endl << "Category: " << category;
        cout << endl << "Price: $" << price; 
    }
};

#endif /* Service_h */

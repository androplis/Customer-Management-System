// Andrew Biddle
// CIS 1202.501
// 12.7.20

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Customer.h"
#include "Service.h"
#include "Payment.h"
using namespace std;

// =========== Function Prototypes ============
int findService(string, vector<Service>);
int findCustomer(string, vector<Customer>);
void openFiles(vector<Service> &, vector<Customer> &);
void saveFiles(vector<Service>, vector<Customer>);

int main() {
    int dashboardSelection, com_dashboardSelection, cust_dashboardSelection, index;
    // Placeholder variables
    Customer customerDemo;
    int customerNum;
    string customerName, address, city, state, zip, email, phone;
    double balance;
    vector<Payment> paymentHistory;
    vector<Service> serviceHistory;
    
    Service serviceDemo;
    int serviceNum;
    string category, serviceName;
    double price;
    
    vector<Customer> customers;
    vector<Service> services;
    
    openFiles(services, customers);
    
    cout << fixed << setprecision(2);
    // ====== WELCOME =======
    cout << endl << " ==============================================================================================";
    cout << endl << " ==============================================================================================" << endl;
    cout << endl << setw(8) << " " << "          ________________      ___________________________      __________________";
    cout << endl << setw(8) << " " << "         /               /     /                          /     /                 /";
    cout << endl << setw(8) << " " << "        /     __________/     /      ____      ____      /     /       __________/";
    cout << endl << setw(8) << " " << "       /     /               /      /   /     /   /     /     /       /          ";
    cout << endl << setw(8) << " " << "      /     /               /      /   /     /   /     /     /       /_________";
    cout << endl << setw(8) << " " << "     /     /               /      /   /     /   /     /     /                 /";
    cout << endl << setw(8) << " " << "    /     /               /      /   /     /   /     /     /_________        /";
    cout << endl << setw(8) << " " << "   /     /               /      /   /     /   /     /               /       /";
    cout << endl << setw(8) << " " << "  /     /__________     /      /   /     /   /     /     __________/       /";
    cout << endl << setw(8) << " " << " /                /    /      /   /     /   /     /     /                 /";
    cout << endl << setw(8) << " " << "/________________/    /______/   /_____/   /_____/     /_________________/ ";
    cout << endl << endl << " ==============================================================================================";
    cout << endl << " ==============================================================================================";
    
    cout << endl << endl << "  WELCOME TO CMS, AN EVERYDAY CUSTOMER MANAGEMENT SYSTEM FOR YOUR EVERYDAY NEEDS.";
    do { // Main program
        dashboardSelection = -1;

        cout << endl << endl << "=============== MENU ==================";
        cout << endl << "1. Company Dashboard\n2. Customer Dashboard\n3. Exit";
        
        while(dashboardSelection < 1 || dashboardSelection > 3) {
            cout << endl << endl << "Enter Selection: ";
            cin >> dashboardSelection;
            // Validate
            if(dashboardSelection < 1 || dashboardSelection > 3) {
                cout << endl << "ERROR: Please enter a valid selection";
            }
        }
        
        if(dashboardSelection == 1) { // Company Dashboard
            do {
                com_dashboardSelection = -1;
                cout << endl << endl << "=============== COMPANY DASHBOARD ==================";
                cout << endl << "1. View All Services\n2. Add a Service\n3. Remove a Service\n4. View Total Income\n5. View Income by Specific Month\n6. Back";
                while(com_dashboardSelection < 1 || com_dashboardSelection > 6) {
                    cout << endl << "Enter Selection: ";
                    cin >> com_dashboardSelection;
                    // Validate
                    if(com_dashboardSelection < 1 || com_dashboardSelection > 6) {
                        cout << endl << "ERROR: Please enter a valid selection.";
                    }
                }
                
                switch(com_dashboardSelection) {
                    case 1: // View All Services
                        for(int i = 0; i < services.size(); i++) {
                            services.at(i).displayService();
                            cout << endl;
                        }
                        break;
                    case 2: // Add a Service
                        cout << endl << "Enter Service Num: ";
                        cin >> serviceNum;
                        cout << endl << "Enter Service Name: ";
                        cin.ignore();
                        getline(cin, serviceName);
                        cout << endl << "Enter Service Category: ";
                        getline(cin, category);
                        cout << endl << "Enter Service Price: ";
                        cin >> price;
                        
                        serviceDemo.setValues(serviceNum, serviceName, category, price);
                        services.push_back(serviceDemo); // Add
                        break;
                    case 3: // Remove a Service
                        cout << endl << "Enter the Service Name: ";
                        cin.ignore();
                        getline(cin, serviceName);
                        index = findService(serviceName, services);
                        
                        if(index != -1) {
                            services.erase(services.begin() + index);
                        }   else {
                            cout << endl << "Could not find the service: " << serviceName;
                        }
                            
                        break;
                    case 4: // View Total Income
                        break;
                    case 5: // View Income by Specific Month
                        break;
                }
            } while (com_dashboardSelection != 6); // Break company dashboard
        }
        
        
        else if(dashboardSelection == 2) { // Customer Dashboard
            do {
                cust_dashboardSelection = -1;
                
                cout << endl << endl << "=============== CUSTOMER DASHBOARD ==================";
                cout << endl << "1. View All Customers\n2. Add a Customer\n3. Remove a Customer\n4. Find a Customer\n5. Update Customer\n6. Record Payment\n7. Record Service\n8. Back";
                
                while(cust_dashboardSelection < 1 || cust_dashboardSelection > 8) {
                    cout << endl << "Enter Selection: ";
                    cin >> cust_dashboardSelection;
                    // Validate
                    if(cust_dashboardSelection < 1 || cust_dashboardSelection > 8) {
                        cout << endl << "ERROR: Please enter a valid selection.";
                    }
                }
                
                switch(cust_dashboardSelection) {
                    case 1: // View All Customers
                        for(int i = 0; i < customers.size(); i++) {
                            customers.at(i).displayCustomerInfo();
                        }
                        break;
                    case 2: // Add a Customer
                        
                        cout << "Enter Customer Number: ";
                        cin >> customerNum;
                        cout << "Enter Full Name: ";
                        cin.ignore();
                        getline(cin, customerName);
                        cout << "Enter Address: ";
                        getline(cin, address);
                        cout << "Enter City: ";
                        getline(cin, city);
                        cout << "Enter State: ";
                        getline(cin, state);
                        cout << "Enter ZIP: ";
                        getline(cin, zip);
                        cout << "Enter Email: ";
                        getline(cin, email);
                        cout << "Enter Phone: ";
                        getline(cin, phone);
                        
                        customerDemo.setValues(customerNum, customerName, address, city, state, zip, email, phone, 0.0);
                        customers.push_back(customerDemo);
                        break;
                    case 3: // Remove a Customer
                        break;
                    case 4: // Find a Customer
                        break;
                    case 5: // Updatae a Customer
                        break;
                    case 6: // Record a Pyament
                        break;
                    case 7: // Record a Service
                        break;
                        break;
                }
            } while(cust_dashboardSelection != 8); // Break customer dashboard
        }
    }  while (dashboardSelection != 3); // Break main program
    
    saveFiles(services, customers);

    cout << endl << "Thank you. Come again.";
    cout << endl << endl;
    return 0;
}

int findService(string serviceName, vector<Service> services) {
    for(int i = 0; i < services.size(); i++) {
        if(services.at(i).getServiceName() == serviceName) {
            return i;
        }
    }
    return -1;
}

// === Opens files and stores contents in vectors
void openFiles(vector<Service> & services, vector<Customer> & customers) {
    // Open files
    fstream customerFile("/Users/andrewbiddle/Sinclair/Fall 2020/C++/Final_Project/customers.dat", ios::in | ios::binary);
    if(customerFile.fail()) {
        cout << endl << "File could not be opened";
    }   else {
        // Read in customer file
        while(!customerFile.eof()) {
            Customer customer;
            customerFile.read(reinterpret_cast<char *>(&customer), sizeof(customer));
            if(customer.getCustomerNum() != 0) {
                customers.push_back(customer);
            }

        }
    }

    fstream serviceFile("/Users/andrewbiddle/Sinclair/Fall 2020/C++/Final_Project/services.dat", ios::in | ios::binary);

    if (serviceFile.fail()) {
        cout << endl << "File could not be opened.";
    }   else {
        // Raad in service file
        while(!serviceFile.eof()) {
            Service service;
            serviceFile.read(reinterpret_cast<char *>(&service), sizeof(service));
            if(service.getServiceNum() != 0) {
                services.push_back(service);
            }
        }
    }
    serviceFile.close();
    customerFile.close();
}

// Svaes contents of vectors into files
void saveFiles(vector<Service> services, vector<Customer> customers) {
    fstream serviceFile("/Users/andrewbiddle/Sinclair/Fall 2020/C++/Final_Project/services.dat", ios::out | ios::trunc | ios::binary);
    
    for(int i = 0; i < services.size(); i++) {
        serviceFile.write(reinterpret_cast<char *>(&services.at(i)), sizeof(services.at(i)));
    }
    serviceFile.close();
    
    fstream customerFile("/Users/andrewbiddle/Sinclair/Fall 2020/C++/Final_Project/customers.dat", ios::out | ios::trunc | ios::binary);
    
    for(int i = 0; i < customers.size(); i++) {
        customerFile.write(reinterpret_cast<char *>(&customers.at(i)), sizeof(customers.at(i)));
    }
    customerFile.close();
}

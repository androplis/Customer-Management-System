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

int main() {
    int dashboardSelection, com_dashboardSelection, cust_dashboardSelection;
    vector<Customer> customers;
    vector<Service> services;
    
    // Open files
    try {
        fstream customerFile("Users/andrewbiddle/Sinclair/Fall 2020/C++/Final_Project/customers.txt", ios::in | ios::out | ios::binary);
    }
    catch(exception ex) {
        cout << endl << "File could not be opened";
    }
    
    try {
        fstream serviceFile("Users/andrewbiddle/Sinclair/Fall 2020/C++/Final_Project/services.txt", ios::in | ios::out | ios::binary);
    }
    catch(exception ex) {
        cout << endl << "File could not be opened.";
    }
    
    // Load customers and service vectors
    
    
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
                cout << endl << "=============== COMPANY DASHBOARD ==================";
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
                        break;
                    case 2: // Add a Service
                        break;
                    case 3: // Remove a Service
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
                
                cout << endl << "=============== CUSTOMER DASHBOARD ==================";
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
                        break;
                    case 2: // Add a Customer
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
    
    cout << endl << endl;
    return 0;
}

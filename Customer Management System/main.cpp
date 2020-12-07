// Andrew Biddle
// CIS 1202.501
// 12.7.20

#include <iostream>
#include <string>
#include "Payment.h"
#include "Service.h"
using namespace std;

int main() {
    Payment payment;
    Service service;
    
    payment.setValues(1, "John Brown", 40.50, "Check", "12.7.20");
    service.setValues(01, "Lawn Mowing", "LAG", 30.00);
    payment.displayPayment();
    service.displayService();
    cout << endl << endl;
    return 0;
}

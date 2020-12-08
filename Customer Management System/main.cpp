// Andrew Biddle
// CIS 1202.501
// 12.7.20

#include <iostream>
#include <string>
#include "Customer.h"
#include "Service.h"
#include "Payment.h"
using namespace std;

int main() {
    Customer bob;
    
    bob.setValues(1, "Bobby", "364 Dakota Run", "Maineville", "OH", "45039", "andrewbiddlebugs@gmail.com", "513-429-6149", 0.00);
    bob.displayCustomerInfo();
    cout << endl << endl;
    return 0;
}

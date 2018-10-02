#include "Queue.h"
#include <string>
#include <iostream>
using namespace std;

struct Customer {
    string name;
    int numItems;
};

const string customerNames[] = {
    "Alma",
    "Brittany",
    "Celeste",
    "David",
    "Emmet",
    "Frank"
};

int main() {
    Queue<Customer> groceryLine;
    Customer myCustomer;

    // Seed random numbers with the current time
    srand(time(NULL));

    // Customers line up
    for(int i = 0; i < 10; ++i) {
        myCustomer.name = customerNames[rand() % 6];
        myCustomer.numItems = rand() % 15;
        cout << "Customer " << myCustomer.name
             << " lined up with " << myCustomer.numItems
             << " items." << endl;
        groceryLine.push(myCustomer);
    }

    // Peek at the next customer
    myCustomer = groceryLine.peek();
    cout << endl;
    cout << "The next customer is " << myCustomer.name << endl;
    cout << endl;

    // Serve Customers
    while(!groceryLine.isEmpty()) {
        myCustomer = groceryLine.pop();
        cout << "Checked out " << myCustomer.numItems << " for "
             << myCustomer.name << "." << endl;
    }

    return 0;
}

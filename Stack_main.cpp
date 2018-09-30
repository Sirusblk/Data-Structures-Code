#include "Stack.h"
#include <string>
#include <iostream>
using namespace std;

enum Pez {
    Lemon,
    Orange,
    Strawberry,
    Cherry,
    Mango,
    Raspberry
};

const string pezNames[] = {"Lemon", "Orange", "Strawberry", "Cherry", "Mango", "Raspberry"};

int main() {
    Stack<Pez> pezDispenser;
    Pez myPez;

    // Seed random numbers with the current time
    srand(time(NULL));

    // Add Pez flavors
    for(int i = 0; i < 10; ++i) {
        myPez = static_cast<Pez>(rand() % Raspberry);
        cout << "Adding Pez flavor " << pezNames[myPez] << endl;
        pezDispenser.push(myPez);
    }

    // Peek at the next flavor
    myPez = pezDispenser.peek();
    cout << endl;
    cout << "The next flavor of Pez is " << pezNames[myPez] << endl;
    cout << endl;

    // Remove Pez flavors
    while(!pezDispenser.isEmpty()) {
        myPez = pezDispenser.pop();
        cout << "Eating Pez flavor " << pezNames[myPez] << endl;
    }

    return 0;
}

#include <iostream>
#include "IteratorLinkedList.h"
#include <cstdlib>
using namespace std;


int main() {
    IteratorLinkedList<int> numbers;
    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        numbers.pushBack(rand() % 1000);
    }

    // Test for-each style loop which only works with iterators!
    // LinkedList class needs: an Iterator class, begin(), end()
    // Iterator class needs: operator*, operator!=, operator++
    for(int num : numbers) {
        cout << num << endl;
    }

    return 0;
}

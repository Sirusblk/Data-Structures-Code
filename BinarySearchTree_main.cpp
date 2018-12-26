#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    BinarySearchTree<int, string> bst;
    bst.put(47, "California");
    bst.put(17, "Aardvark");
    bst.put(32, "Bokoblin");
    bst.put(65, "Rum");
    
    bst.erase(32);
    
    // Tests
    assert(bst.get(17) == "Aardvark");
    assert(bst.get(47) == "California");
    assert(bst.get(65) == "Rum");

    try {
        cout << "Looking for key 32" << endl;
        bst.get(32);
        cout << "ERROR: Expected exception to be thrown!" << endl;
    } catch (logic_error e) {
        cout << "Exception: " << e.what() << endl;
        cout << "Test passed!" << endl;
    }
    
    return 0;
}

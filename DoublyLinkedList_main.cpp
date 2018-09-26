#include <stdexcept>
#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
using namespace std;

class Student {
private:
    string name;
    int numSemesters;

public:
    void print() {
        cout << "Name:" << name << "; No. of semesters=" << numSemesters << endl;
    }
    void setName(string newName) {
        name = newName;
    }
    void setNumSemesters(int n) {
        numSemesters = n;
    }
    void updateNSemesters() {
        numSemesters++;
    }
};


int main() {
    DoublyLinkedList<Student> students;

    Student newStudent;

    for (int i = 0; i < 5; i++) {
        newStudent.setName("Student_" + to_string(i));
        newStudent.setNumSemesters(2);
        students.pushFront(newStudent);
    }

    for (int i = 0; i < 5; i++) {
        newStudent.setName("Student_" + to_string(i + 50));
        newStudent.setNumSemesters(2);
        students.pushBack(newStudent);       // can also insert at the end
    }

    while (!students.isEmpty()) {
        students.getTail()->data.print();
        students.remove(students.getTail());
    }

    return 0;
}

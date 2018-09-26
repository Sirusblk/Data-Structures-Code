#pragma once

#include <stdexcept>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node<T>* prevPtr;
    Node<T>* nextPtr;
};


template<typename T>
class DoublyLinkedList {
private:
    int size;
    Node<T>* head;
    Node<T>* tail;
public:
    // Constructors
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList&);
    ~DoublyLinkedList();

    // Getters / Setters
    int getSize();
    bool isEmpty();
    Node<T>* getHead();
    Node<T>* getTail();

    void clear();
    void pushFront(T);
    void pushBack(T);
    void insertAfter(Node<T>*, T);
    void remove(Node<T>*);

    // Overloaded Operators
    DoublyLinkedList& operator=(const DoublyLinkedList&);
};


// DoublyLinkedList Member Functions
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& input) {
    size = input.size;
    head = input.head;
    tail = input.tail;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
int DoublyLinkedList<T>::getSize() {
    return size;
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() {
    return (size == 0);
}

template<typename T>
Node<T>* DoublyLinkedList<T>::getHead() {
    return head;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::getTail() {
    return tail;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    if (head != nullptr) {
        while(head != nullptr) {
            remove(head);
        }
    }
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void DoublyLinkedList<T>::pushFront(T newData) {
    // Construct new node
    Node<T>* newNode = new Node<T>();
    newNode->data = newData;
    newNode->prevPtr = nullptr;
    newNode->nextPtr = nullptr;

    if (isEmpty()) {                // List empty
        head = newNode;
        tail = newNode;
    } else {
        newNode->nextPtr = head;
        head->prevPtr = newNode;
        head = newNode;
    }
    size++;
}

template<typename T>
void DoublyLinkedList<T>::pushBack(T newData) {
    // Construct new node
    Node<T>* newNode = new Node<T>();
    newNode->data = newData;
    newNode->prevPtr = nullptr;
    newNode->nextPtr = nullptr;

    if (isEmpty()) {                // List empty
        head = newNode;
        tail = newNode;
    } else {
        tail->nextPtr = newNode;
        newNode->prevPtr = tail;
        tail = newNode;
    }
    size++;
}

template<typename T>
void DoublyLinkedList<T>::insertAfter(Node<T>* pos, T newData) {
    // Construct new node
    Node<T>* newNode = new Node<T>();
    newNode->data = newData;
    newNode->prevPtr = nullptr;
    newNode->nextPtr = nullptr;

    if (isEmpty()) {                // List empty
        head = newNode;
        tail = newNode;
    } else if (pos == tail) {       // Insert after tail
        tail->nextPtr = newNode;
        newNode->prevPtr = tail;
        tail = newNode;
    } else {
        Node<T>* temp = pos->nextPtr;

        newNode->nextPtr = temp;
        newNode->prevPtr = pos;
        pos->nextPtr = newNode;

        temp->prevPtr = newNode;
    }
    size++;
}

template<typename T>
void DoublyLinkedList<T>::remove(Node<T>* pos) {
    Node<T>* prevNode = pos->prevPtr;
    Node<T>* nextNode = pos->nextPtr;

    if (isEmpty()) {
        throw length_error("Your DoublyLinkedList is empty");
    }

    if (nextNode != nullptr) {
        nextNode->prevPtr = prevNode;
    }

    if (prevNode != nullptr) {
        prevNode->nextPtr = nextNode;
    }

    if (head == pos) {          // Remove head
        head = nextNode;
    }

    if (tail == pos) {          // Remove tail
        tail = prevNode;
    }

    // delete pos;
    size--;
}

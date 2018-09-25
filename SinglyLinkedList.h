#pragma once

#include <stdexcept>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node<T>* nextPtr;
};


template<typename T>
class SinglyLinkedList {
private:
    int size;
    Node<T>* head;
    Node<T>* tail;
public:
    // Constructors
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList&);
    ~SinglyLinkedList();

    // Getters / Setters
    int getSize();
    bool isEmpty();
    Node<T>* getHead();

    void clear();
    void pushFront(T);
    void pushBack(T);
    void insertAfter(Node<T>*, T);
    void removeAfter(Node<T>*);

    // Overloaded Operators
    SinglyLinkedList& operator=(const SinglyLinkedList&);
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList& input) {
    size = input.size;
    head = input.head;
    tail = input.tail;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template<typename T>
int SinglyLinkedList<T>::getSize() {
    return size;
}

template<typename T>
bool SinglyLinkedList<T>::isEmpty() {
    return (size == 0);
}

template<typename T>
Node<T>* SinglyLinkedList<T>::getHead() {
    return head;
}

template<typename T>
void SinglyLinkedList<T>::clear() {
    if (head != nullptr) {
        while(head->nextPtr != nullptr) {
            removeAfter(head);
        }
        delete head;
    }
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void SinglyLinkedList<T>::pushFront(T newData) {
    if (isEmpty()) {
        head = new Node<T>();
        head->data = newData;
        head->nextPtr = nullptr;
        tail = head;
    } else {
        Node<T>* temp = head;
        head = new Node<T>();
        head->data = newData;
        head->nextPtr = temp;
    }
    size++;
}

template<typename T>
void SinglyLinkedList<T>::pushBack(T newData) {
    if (isEmpty()) {
        head = new Node<T>();
        head->data = newData;
        head->nextPtr = nullptr;
        tail = head;
    } else {
        Node<T>* temp = tail;
        tail = new Node<T>();
        tail->data = newData;
        tail->nextPtr = nullptr;
        temp->nextPtr = tail;
    }
    size++;
}

template<typename T>
void SinglyLinkedList<T>::insertAfter(Node<T>* pos, T newData) {
    if (isEmpty()) {
        pushFront(newData);
    } else {
        Node<T>* newNode = new Node<T>();
        newNode->data = newData;
        newNode->nextPtr = pos->nextPtr;
        pos->nextPtr = newNode;
    }
    size++;
}

template<typename T>
void SinglyLinkedList<T>::removeAfter(Node<T>* pos) {
    if (isEmpty()) {
        throw length_error("Your SinglyLinkedList is empty");
    } else if (pos->nextPtr == nullptr) {
        throw out_of_range("You cannot remove anything past the tail node");
    } else {
        Node<T>* temp = pos->nextPtr->nextPtr;
        delete pos->nextPtr;
        pos->nextPtr = temp;
        size--;
    }
}

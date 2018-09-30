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
class IteratorLinkedList {
private:
    int size;
    Node<T>* head;
    Node<T>* tail;
public:
    class Iterator {
    private:
        Node<T>* ptr;
    public:
        Iterator();
        Iterator(Node<T>*);
        Iterator(const Iterator&);
        ~Iterator();

        T operator*();
        Iterator operator++();
        Iterator operator--();
        Iterator operator=(const Iterator&);
        bool operator==(const Iterator&);
        bool operator!=(const Iterator&);
    };

    // Constructors
    IteratorLinkedList();
    IteratorLinkedList(const IteratorLinkedList&);
    ~IteratorLinkedList();

    // Getters / Setters
    int getSize();
    bool isEmpty();
    Node<T>* getHead();
    Node<T>* getTail();
    Iterator begin();
    Iterator end();

    void clear();
    void pushFront(T);
    void pushBack(T);
    void insertAfter(Node<T>*, T);
    void remove(Node<T>*);

    // Overloaded Operators
    IteratorLinkedList& operator=(const IteratorLinkedList&);
};


// Iterator Member Functions
template<typename T>
IteratorLinkedList<T>::Iterator::Iterator() {
    ptr = nullptr;
}

template<typename T>
IteratorLinkedList<T>::Iterator::Iterator(Node<T>* newPtr) {
    ptr = newPtr;
}

template<typename T>
IteratorLinkedList<T>::Iterator::Iterator(const Iterator& newIterator) {
    ptr = newIterator.ptr;
}

template<typename T>
IteratorLinkedList<T>::Iterator::~Iterator() {
    ptr = nullptr;
}

template<typename T>
T IteratorLinkedList<T>::Iterator::operator*() {
    return ptr->data;
}

template<typename T>
typename IteratorLinkedList<T>::Iterator IteratorLinkedList<T>::Iterator::operator++() {
    ptr = ptr->nextPtr;
    return *this;
}

template<typename T>
typename IteratorLinkedList<T>::Iterator IteratorLinkedList<T>::Iterator::operator--() {
    ptr = ptr->prevPtr;
    return *this;
}

template<typename T>
typename IteratorLinkedList<T>::Iterator IteratorLinkedList<T>::Iterator::operator=(const Iterator& rhs) {
    ptr = rhs->ptr;
    return *this;
}

template<typename T>
bool IteratorLinkedList<T>::Iterator::operator==(const Iterator& rhs) {
    return (ptr == rhs.ptr);
}

template<typename T>
bool IteratorLinkedList<T>::Iterator::operator!=(const Iterator& rhs) {
    return (ptr != rhs.ptr);
}


// IteratorLinkedList Member Functions
template<typename T>
IteratorLinkedList<T>::IteratorLinkedList() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
IteratorLinkedList<T>::IteratorLinkedList(const IteratorLinkedList& input) {
    size = input.size;
    head = input.head;
    tail = input.tail;
}

template<typename T>
IteratorLinkedList<T>::~IteratorLinkedList() {
    clear();
}

template<typename T>
int IteratorLinkedList<T>::getSize() {
    return size;
}

template<typename T>
bool IteratorLinkedList<T>::isEmpty() {
    return (size == 0);
}

template<typename T>
Node<T>* IteratorLinkedList<T>::getHead() {
    return head;
}

template<typename T>
Node<T>* IteratorLinkedList<T>::getTail() {
    return tail;
}

template<typename T>
typename IteratorLinkedList<T>::Iterator IteratorLinkedList<T>::begin() {
    return Iterator(head);
}

template<typename T>
typename IteratorLinkedList<T>::Iterator IteratorLinkedList<T>::end() {
    return Iterator(tail);
}

template<typename T>
void IteratorLinkedList<T>::clear() {
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
void IteratorLinkedList<T>::pushFront(T newData) {
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
void IteratorLinkedList<T>::pushBack(T newData) {
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
void IteratorLinkedList<T>::insertAfter(Node<T>* pos, T newData) {
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
void IteratorLinkedList<T>::remove(Node<T>* pos) {
    Node<T>* prevNode = pos->prevPtr;
    Node<T>* nextNode = pos->nextPtr;

    if (isEmpty()) {
        throw length_error("Your IteratorLinkedList is empty");
    }

    if (nextNode != nullptr) {
        nextNode->prevPtr = prevNode;
    }

    if (prevNode != nullptr) {
        prevNode->nextPtr = nextNode;
    }

    if (pos == head) {          // Remove head
        head = nextNode;
    }

    if (pos == tail) {          // Remove tail
        tail = prevNode;
    }

    delete pos;
    size--;
}

#include <list>
using namespace std;

template <typename T>
class Queue {
private:
    list<T> myQueue;
public:
    Queue();

    void push(T);
    T pop();
    T peek();
    bool isEmpty();
    int getLength();
};

template <typename T>
Queue<T>::Queue() {
}

template <typename T>
void Queue<T>::push(T newVal) {
    myQueue.push_back(newVal);
}

template <typename T>
T Queue<T>::pop() {
    T top = myQueue.front();
    myQueue.pop_front();
    return top;
}

template <typename T>
T Queue<T>::peek() {
    T top = myQueue.front();
    return top;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return myQueue.empty();
}

template <typename T>
int Queue<T>::getLength() {
    return myQueue.size();
}

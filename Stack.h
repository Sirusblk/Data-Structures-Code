#include <forward_list>
using namespace std;

template <typename T>
class Stack {
private:
    forward_list<T> list;
    int size;
public:
    Stack();

    void push(T);
    T pop();
    T peek();
    bool isEmpty();
    int getLength();
};

template <typename T>
Stack<T>::Stack() {
    size = 0;
}

template <typename T>
void Stack<T>::push(T newVal) {
    list.push_front(newVal);
    size++;
}

template <typename T>
T Stack<T>::pop() {
    T top = list.front();
    list.pop_front();
    size--;
    return top;
}

template <typename T>
T Stack<T>::peek() {
    T top = list.front();
    return top;
}

template <typename T>
bool Stack<T>::isEmpty() {
    return list.empty();
}

template <typename T>
int Stack<T>::getLength() {
    return size;
}

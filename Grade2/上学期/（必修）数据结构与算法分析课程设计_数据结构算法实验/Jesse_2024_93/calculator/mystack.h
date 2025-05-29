#include <iostream>
#define MAX_SIZE 100
using namespace std;
template <class T>
class mystack {
private:
    T stack[MAX_SIZE] = {0};
    int temp = -1;

public:
    void mypush(T x);
    void mypop();
    bool myisEmpty();
    T mytop();
};
template <class T>
void mystack<T>::mypush(T x) {
    if (temp > MAX_SIZE - 1) {
        cout << "Error: The stack is full!" << endl;
        return;
    }
    temp++;
    stack[temp] = x;
}

template <class T>
void mystack<T>::mypop() {
    if (myisEmpty()) {
        cout << "Error: The stack is empty!" << endl;
        return;
    }
    stack[temp] = 0;
    temp--;
}

template <class T>
bool mystack<T>::myisEmpty() {
    return (temp == -1);
}

template <class T>
T mystack<T>::mytop() {
    if (myisEmpty()) {
        cout << "Error: The stack is empty!" << endl;
        return T(0);
    }
    return stack[temp];
}
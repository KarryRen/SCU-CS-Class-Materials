#ifndef STACK_H
#define STACK_H

#include <iostream>  
#include <string>  
#include <cctype>  
#include <cmath>
#include <vector>

using namespace std;

template <class T>
class Stack
{
private:

    struct Node {
        T data;
        Node* next;
    };

    Node* head;

public:
    Stack() : head(NULL) {}

    void push(T d)
    {
        Node* q = new Node;
        q->data = d;
        q->next = head;
        head = q;
    }

    bool pop(T& d)
    {
        if (head == NULL) return false;
        Node* q = head;
        d = q->data;
        head = head->next;
        delete q;
        return true;
    }

    bool top(T& d)
    {
        if (head == NULL) return false;
        Node* q = head;
        d = q->data;
    }


    bool isEmpty() const
    {
        return head == NULL;
    }
};

#endif // !STACK_H



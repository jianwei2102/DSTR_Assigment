#pragma once


#include <iostream>
using namespace std;

template <class T>
struct node {
    T data;
    node<T>* next;
    node<T>* prev;
};

template<class T>
class Stack {
    node<T>* top = NULL;
    node<T>* bottom = NULL;
    int size = 0;
    string stackName = "";

public:
    Stack(string stackName) {
        this->stackName = stackName;
    };

    bool isEmpty();
    void Push(T data);
    T Pop();
    T Peek();
    string getStackName();

};

template <class T>
bool Stack<T>::isEmpty()
{
    if (top == NULL)
        return true;
    return false;
};

template <class T>
void Stack<T>::Push(T data)
{
    node <T>* newnode = new node <T>;
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (top == NULL) {
        top = bottom = newnode;
    }
    else {
        top->prev = newnode;
        newnode->next = top;
        top = newnode;
    }
    size++;

}

template <class T>
T Stack<T>::Pop() {
    T tempdata;
    if (!isEmpty())
    {
        node<T>* current = top;
        top = top->next;
        if (top == NULL) {
            bottom = NULL;
        }
        else {
            top->prev = NULL;
        }

        tempdata = current->data;
        delete current;
        size--;
        return tempdata;
    }

    cout << "Stack Underflow!" << endl;
}

template <class T>
T Stack<T>::Peek()
{
    if (!isEmpty()) {
        return top->data;
    }

    cout << "Stack underflow!" << endl;
}

template <class T>
string Stack<T>::getStackName() {
    return stackName;
}
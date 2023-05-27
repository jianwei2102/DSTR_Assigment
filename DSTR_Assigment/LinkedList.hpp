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
class LinkedList {
public:

    node<T>* head = NULL;
    node<T>* tail = NULL;

    void insertNodeToEnd(T data);
    void insertNodeToFront(T data);
    void removeSpecificNode(node<T>*);


};

template<class T>
void LinkedList<T>::insertNodeToEnd(T data)
{
    node<T>* newNode = new node<T>;
    newNode->data = data;

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}


template<class T>
void LinkedList<T>::insertNodeToFront(T data) 
{
    node<T>* newNode = new node<T>;
    newNode->data = data;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}


template<class T>
void LinkedList<T>::removeSpecificNode(node<T>*)
{

}




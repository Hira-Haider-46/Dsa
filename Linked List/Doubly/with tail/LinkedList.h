#include "node.h"

template <class T>
class LinkedList
{
protected:
    node<T> *tail;

public:
    LinkedList() : tail(nullptr) {}
    void insertAtTail(T val);
    void deleteFromTail();
    void insertAtHead(T val);
    void deleteFromHead();
    void display();
    ~LinkedList() 
    {
        while (tail != nullptr) deleteFromTail();
    }
};

template <class T>
void LinkedList<T>::insertAtTail(T val)
{
    node<T> *newnode = new node<T>(val);
    if (tail == nullptr)
    {
        tail = newnode;
        tail->next = tail->prev = nullptr;
    }
    else
    {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

template <class T>
void LinkedList<T>::deleteFromTail()
{
    if (tail == nullptr)
    {
        cout << "Already empty, cannot delete from tail" << endl;
        return;
    }
    if (tail->prev == nullptr)
    {
        delete tail;
        tail = nullptr;
        return;
    }
    node<T> *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}

template <class T>
void LinkedList<T>::insertAtHead(T val)
{
    node<T> *newnode = new node<T>(val);
    if (tail == nullptr)
    {
        tail = newnode;
        tail->next = tail->prev = nullptr;
    }
    else
    {
        node<T> *temp = tail;
        while(temp->prev != nullptr) temp = temp->prev;
        temp->prev = newnode;
        newnode->next = temp;
    }
}

template <class T>
void LinkedList<T>::deleteFromHead()
{
    if (tail == nullptr)
    {
        cout << "Already empty, cannot delete from head" << endl;
        return;
    }
    if (tail->prev == nullptr)
    {
        delete tail;
        tail = nullptr;
        return;
    }
    node<T> *temp = tail;
    while(temp->prev->prev != nullptr) temp = temp->prev;
    delete temp->prev;
    temp->prev = nullptr;
}

template <class T>
void LinkedList<T>::display()
{
    if (tail == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }
    node<T> *temp = tail;
    while(temp->prev != nullptr) temp = temp->prev;
    while(temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
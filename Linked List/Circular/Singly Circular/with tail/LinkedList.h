#include "node.h"

template <class T>
class LinkedList
{
protected:
    node<T> *tail;

public:
    LinkedList() : tail(nullptr) {}
    void insertAtEnd(T val);
    void deleteFromEnd();
    void insertAtHead(T val);
    void deleteFromHead();
    void display();
    ~LinkedList() {}
};

template <class T>
void LinkedList<T>::insertAtEnd(T val)
{
    node<T> *newNode = new node<T>(val);
    if (tail == nullptr)
    {
        newNode->next = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

template <class T>
void LinkedList<T>::deleteFromEnd()
{
    if (tail == nullptr)
    {
        cout << "Already empty cannot delete from end" << endl;
        return;
    }
    if (tail->next == tail)
    {
        delete tail;
        tail = nullptr;
        return;
    }
    node<T> *temp = tail->next;
    while (temp->next != tail) temp = temp->next;
    temp->next = tail->next;
    delete tail;
    tail = temp;
}

template <class T>
void LinkedList<T>::insertAtHead(T val)
{
    node<T> *newNode = new node<T>(val);
    if (tail == nullptr)
    {
        newNode->next = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

template <class T>
void LinkedList<T>::deleteFromHead()
{
    if (tail == nullptr)
    {
        cout << "Already empty cannot delete from head" << endl;
        return;
    }
    if (tail->next == tail)
    {
        delete tail;
        tail = nullptr;
        return;
    }
    node<T> *temp = tail->next;
    tail->next = temp->next;
    delete temp;
}

template <class T>
void LinkedList<T>::display()
{
    if (tail == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    cout << endl;
    node<T> *temp = tail->next;
    cout << "List: ";
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "Head" << endl;
}
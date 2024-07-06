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
    ~LinkedList()
    {
        if (tail != nullptr)
        {
            node<T> *current = tail->next;
            while (current != tail)
            {
                node<T> *temp = current;
                current = current->next;
                delete temp;
            }
            delete tail;
        }
    }
};

template <class T>
void LinkedList<T>::insertAtEnd(T val)
{
    node<T> *newnode = new node<T>(val);
    if (tail == nullptr)
    {
        tail = newnode;
        tail->next = tail;
        tail->prev = tail;
    }
    else
    {
        node<T> *head = tail->next;
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
        tail = newnode;
    }
}

template <class T>
void LinkedList<T>::deleteFromEnd()
{
    if (tail == nullptr)
    {
        cout << "Already empty, cannot delete from end" << endl;
        return;
    }
    if (tail->next == tail)
    {
        delete tail;
        tail = nullptr;
        return;
    }
    node<T> *head = tail->next;
    node<T> *temp = tail->prev;
    temp->next = tail->next;
    head->prev = temp;
    delete tail;
    tail = temp;
}

template <class T>
void LinkedList<T>::insertAtHead(T val)
{
    node<T> *newnode = new node<T>(val);
    if (tail == nullptr)
    {
        tail = newnode;
        tail->next = tail;
        tail->prev = tail;
    }
    else
    {
        node<T> *head = tail->next;
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
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
    if (tail->next == tail)
    {
        delete tail;
        tail = nullptr;
        return;
    }
    node<T> *head = tail->next;
    tail->next = head->next;
    head->next->prev = tail;
    delete head;
}

template <class T>
void LinkedList<T>::display()
{
    if (tail == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }
    node<T> *head = tail->next;
    while (head != tail)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data << "->";
    cout << "Head" << endl;
}
#include "node.h"

template <class T>
class LinkedList
{
protected:
    node<T> *head;
    node<T> *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void insertAtTail(T val);
    void deleteFromTail();
    void insertAtHead(T val);
    void deleteFromHead();
    void display();
    void clear();
    ~LinkedList()
    {
        clear();
    }
};

template <class T>
void LinkedList<T>::clear()
{
    node<T> *current = head;
    while (current != nullptr)
    {
        node<T> *next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
}

template <class T>
void LinkedList<T>::insertAtTail(T val)
{
    node<T> *newNode = new node<T>(val);
    if (head == nullptr)
    {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

template <class T>
void LinkedList<T>::deleteFromTail()
{
    if (tail == nullptr)
    {
        cout << "Already empty, cannot delete from tail" << endl;
        return;
    }
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
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
    node<T> *newNode = new node<T>(val);
    if (head == nullptr)
    {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

template <class T>
void LinkedList<T>::deleteFromHead()
{
    if (head == nullptr)
    {
        cout << "Already empty, cannot delete from head" << endl;
        return;
    }
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }
    node<T> *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}

template <class T>
void LinkedList<T>::display()
{
    if (head == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }
    node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
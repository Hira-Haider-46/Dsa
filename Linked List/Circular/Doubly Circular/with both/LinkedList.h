#include "node.h"

template <class T>
class LinkedList
{
protected:
    node<T> *head;
    node<T> *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void insertAtEnd(T val);
    void deleteFromEnd();
    void insertAtHead(T val);
    void deleteFromHead();
    void display();
    ~LinkedList()
    {
        if (head != nullptr)
        {
            node<T> *current = head->next;
            while (current != head)
            {
                node<T> *temp = current;
                current = current->next;
                delete temp;
            }
            delete head;
        }
    }
};

template <class T>
void LinkedList<T>::insertAtEnd(T val)
{
    node<T> *newnode = new node<T>(val);
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        newnode->prev = tail;
        newnode->next = head;
        tail->next = newnode;
        head->prev = newnode;
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
    if (tail == head)
    {
        delete tail;
        head = tail = nullptr;
        return;
    }
    node<T> *temp = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete temp;
}

template <class T>
void LinkedList<T>::insertAtHead(T val)
{
    node<T> *newnode = new node<T>(val);
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
        head = newnode;
    }
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
        head = nullptr;
        tail = nullptr;
        return;
    }
    node<T> *temp = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;
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
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD" << endl;
}
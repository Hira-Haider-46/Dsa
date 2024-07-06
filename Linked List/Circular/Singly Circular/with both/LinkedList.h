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
        if (head == nullptr) return;
        node<T> *current = head;
        do
        {
            node<T> *nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
        head = tail = nullptr;
    }
};

template <class T>
void LinkedList<T>::insertAtEnd(T val)
{
    node<T> *newNode = new node<T>(val);
    if (head == nullptr)
    {
        newNode->next = newNode;
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

template <class T>
void LinkedList<T>::deleteFromEnd()
{
    if (head == nullptr)
    {
        cout << "Already empty, cannot delete from end" << endl;
        return;
    }
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }
    node<T> *temp = head;
    while (temp->next != tail) temp = temp->next;
    temp->next = head;
    delete tail;
    tail = temp;
}

template <class T>
void LinkedList<T>::insertAtHead(T val)
{
    node<T> *newNode = new node<T>(val);
    if (head == nullptr)
    {
        newNode->next = newNode;
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

template <class T>
void LinkedList<T>::deleteFromHead()
{
    if (head == nullptr)
    {
        cout << "Already empty cannot delete from head" << endl;
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
    tail->next = head;
    delete temp;
}

template <class T>
void LinkedList<T>::display()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    cout << endl;
    node<T> *temp = head;
    cout << "List: ";
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << "Head" << endl;
}
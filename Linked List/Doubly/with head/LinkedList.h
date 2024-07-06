#include "node.h"

template <class T>
class LinkedList
{
protected:
    node<T> *head;

public:
    LinkedList() : head(nullptr) {}
    void insertAtEnd(T val);
    void deleteFromEnd();
    void insertAtHead(T val);
    void deleteFromHead();
    void display();
    ~LinkedList()
    {
        node<T> *current = head;
        while (current != nullptr)
        {
            node<T> *n = current->next;
            delete current;
            current = n;
        }
        head = nullptr;
    }
};

template <class T>
void LinkedList<T>::insertAtEnd(T val)
{
    node<T> *newNode = new node<T>(val);
    if (this->head == nullptr)
    {
        insertAtHead(val);
        return;
    }
    node<T> *temp = this->head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

template <class T>
void LinkedList<T>::deleteFromEnd()
{
    if (head == nullptr)
    {
        cout << "Already empty cannot delete from end" << endl;
        return;
    }
    node<T> *temp = head;
    if (temp->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    while (temp->next->next != nullptr) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

template <class T>
void LinkedList<T>::insertAtHead(T val)
{
    node<T> *n = new node<T>(val);
    if (this->head == nullptr)
    {
        head = n;
        return;
    }
    head->prev = n;
    n->next = head;
    head = n;
}

template <class T>
void LinkedList<T>::deleteFromHead()
{
    if (this->head == nullptr)
    {
        cout << "Already empty cannot delete from head" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
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
    if (this->head == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }
    cout << endl;
    node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
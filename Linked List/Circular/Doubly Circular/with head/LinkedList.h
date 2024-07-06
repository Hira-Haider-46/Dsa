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
        if (head != nullptr)
        {
            node<T> *current = head->next;
            node<T> *temp;
            while (current != head)
            {
                temp = current;
                current = current->next;
                delete temp;
            }
            delete head;
            head = nullptr;
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
        head->next = head;
        head->prev = head;
    }
    else
    {
        node<T> *tail = head->prev;
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
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
    if (head->next == head)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        node<T> *tail = head->prev;
        node<T> *newTail = tail->prev;
        newTail->next = head;
        head->prev = newTail;
        delete tail;
    }
}

template <class T>
void LinkedList<T>::insertAtHead(T val)
{
    node<T> *newnode = new node<T>(val);
    if (head == nullptr)
    {
        head = newnode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        node<T> *tail = head->prev;
        newnode->next = head;
        newnode->prev = tail;
        tail->next = newnode;
        head->prev = newnode;
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
    if (head->next == head)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        node<T> *tail = head->prev;
        node<T> *newHead = head->next;
        tail->next = newHead;
        newHead->prev = tail;
        delete head;
        head = newHead;
    }
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
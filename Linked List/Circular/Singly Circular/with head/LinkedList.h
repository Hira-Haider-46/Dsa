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
        if (this->head == nullptr) return;
        node<T> *temp = this->head;
        do
        {
            node<T> *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != this->head);
        this->head = nullptr;
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
    while (temp->next != this->head) temp = temp->next;
    temp->next = newNode;
    newNode->next = this->head;
}

template <class T>
void LinkedList<T>::deleteFromEnd()
{
    if (this->head == nullptr)
    {
        cout << "Already empty cannot delete from end" << endl;
        return;
    }
    node<T> *temp = this->head;
    if (temp->next == this->head)
    {
        delete this->head;
        this->head = nullptr;
        return;
    }
    while (temp->next->next != this->head) temp = temp->next;
    delete temp->next;
    temp->next = this->head;
}

template <class T>
void LinkedList<T>::insertAtHead(T val)
{
    node<T> *n = new node<T>(val);
    if (this->head == nullptr)
    {
        n->next = n;
        this->head = n;
        return;
    }
    node<T> *temp = this->head;
    while (temp->next != this->head) temp = temp->next;
    temp->next = n;
    n->next = this->head;
    this->head = n;
}

template <class T>
void LinkedList<T>::deleteFromHead()
{
    if (this->head == nullptr)
    {
        cout << "Already empty cannot delete from head" << endl;
        return;
    }
    if (this->head->next == this->head)
    {
        delete this->head;
        this->head = nullptr;
        return;
    }
    node<T> *temp = this->head;
    while (temp->next != this->head) temp = temp->next;
    temp->next = head->next;
    delete this->head;
    this->head = temp->next;
}

template <class T>
void LinkedList<T>::display()
{
    if (this->head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    cout << endl;
    node<T> *temp = this->head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != this->head);
    cout << "Head" << endl;
}

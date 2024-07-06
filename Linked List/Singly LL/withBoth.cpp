#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node() : data(T()), next(nullptr) {}
    Node(T value) : data(value), next(nullptr) {}
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void insertAtHead(T value);
    void insertAtTail(T value);
    void deleteFromHead();
    void deleteFromTail();
    int size();
    void display();
    void clear();
    ~LinkedList()
    {
        clear();
    }
};

template <class T>
void LinkedList<T>::insertAtHead(T value)
{
    Node<T> *n = new Node<T>(value);
    if (head == nullptr)
    {
        head = tail = n;
        return;
    }
    n->next = head;
    head = n;
}

template <class T>
void LinkedList<T>::insertAtTail(T value)
{
    Node<T> *n = new Node<T>(value);
    if (head == nullptr)
    {
        head = tail = n;
        return;
    }
    tail->next = n;
    tail = n;
}

template <class T>
void LinkedList<T>::deleteFromHead()
{
    if (head == nullptr)
    {
        cout << "Cannot delete, linked list is empty" << endl;
        return;
    }
    Node<T> *temp = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete temp;
}

template <class T>
void LinkedList<T>::deleteFromTail()
{
    if (head == nullptr)
    {
        cout << "Already empty" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = tail = nullptr;
        return;
    }
    Node<T> *temp = head;
    while (temp->next != tail) temp = temp->next;
    delete tail;
    tail = temp;
    tail->next = nullptr;
}

template <class T>
int LinkedList<T>::size()
{
    int count = 0;
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

template <class T>
void LinkedList<T>::display()
{
    cout << endl;
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

template <class T>
void LinkedList<T>::clear()
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
}

int main()
{
    LinkedList<int> ll;
    int choice, value;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Delete from Head\n";
        cout << "4. Delete from Tail\n";
        cout << "5. Size of List\n";
        cout << "6. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at head: ";
            cin >> value;
            ll.insertAtHead(value);
            ll.display();
            break;
        case 2:
            cout << "Enter value to insert at tail: ";
            cin >> value;
            ll.insertAtTail(value);
            ll.display();
            break;
        case 3:
            ll.deleteFromHead();
            ll.display();
            break;
        case 4:
            ll.deleteFromTail();
            ll.display();
            break;
        case 5:
            cout << "Size of list: " << ll.size() << endl;
            break;
        case 6:
            ll.display();
            break;
        case 0:
            cout << "Exiting" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
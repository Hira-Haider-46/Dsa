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
    void insertAtHead(Node<T> *&head, int value);
    void insertAtTail(Node<T> *&head, int value);
    void deleteFromHead(Node<T> *&head);
    void deleteFromTail(Node<T> *&head);
    int size(Node<T> *&head);
    void display(Node<T> *&head);
    void clear(Node<T> *&head);
    bool search(Node<T> *head, int value);
    bool BinarySearch(Node<T> *&head, int value);
    Node<T> *mid(Node<T> *head);
    T middleElement(Node<T> *head);
    void DeletemiddleElement(Node<T> *&head);
    void reverse(Node<T> *&head);
    Node<T> *reverseKtimes(Node<T> *&head, int k);
    Node<T> *removeNnodeFromEnd(Node<T> *&head, int n);
    void FindNnodeFromEnd(Node<T> *&head, int n);
    void deleteNnode(Node<T> *&head, int n);
    void sort(Node<T> *head);
    void removeDuplicatesSorted(Node<T> *&head);
    void removeDuplicatesUnSorted(Node<T> *&head);
    ~Node()
    {
        //clear();
    }
};

template <class T>
void Node<T>::insertAtHead(Node<T> *&head, int value)
{
    Node<T> *n = new Node<T>(value);
    if (head == nullptr)
    {
        head = n;
        return;
    }
    n->next = head;
    head = n;
}

template <class T>
void Node<T>::insertAtTail(Node<T> *&head, int value)
{
    Node<T> *n = new Node<T>(value);
    if (head == nullptr)
    {
        head = n;
        return;
    }
    Node<T> *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = n;
}

template <class T>
void Node<T>::deleteFromHead(Node<T> *&head)
{
    if (head == nullptr)
    {
        cout << "Cannot delete linked list is empty" << endl;
        return;
    }
    Node<T> *temp = head->next;
    delete head;
    head = temp;
}

template <class T>
void Node<T>::deleteFromTail(Node<T> *&head)
{
    if (head == nullptr)
    {
        cout << "Already empty" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node<T> *temp = head;
    while (temp->next->next != nullptr) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

template <class T>
bool Node<T>::search(Node<T> *head, int value)
{
    Node<T> *temp = head;
    //int count = 0;
    while (temp != nullptr && temp->data != value)
    {
        temp = temp->next;
        //count++;
    }
    if (temp != nullptr)
    {
        //cout << value << " is found at index " << count << endl;
        return true;
    }
    else
    {
        //cout << "Not found" << endl;
        return false;
    }
}

template <class T>
bool Node<T>::BinarySearch(Node<T> *&head, int value)
{
    Node<T> *start = head;
    Node<T> *end = nullptr;
    while (start != end)
    {
        Node<T> *middle = mid(start, end);
        if (mid->data == value) return true;
        else if (mid->data > value) end = mid;
        else start = mid->next;
    }
    return false;
}

template <class T>
Node<T> *Node<T>::mid(Node<T> *head)
{
    if (head == nullptr) return nullptr;
    Node<T> *slow = head;
    Node<T> *fast = head->next;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <class T>
T Node<T>::middleElement(Node<T> *head)
{
    Node<T> *slow = head;
    Node<T> *fast = head->next;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

template <class T>
void Node<T>::DeletemiddleElement(Node<T> *&head)
{
    if (head == nullptr || head->next == nullptr) return;
    Node<T> *slow = head;
    Node<T> *fast = head->next;
    Node<T> *prev = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
}

template <class T>
int Node<T>::size(Node<T> *&head)
{
    int count = 0;
    Node<T> *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

template <class T>
void Node<T>::display(Node<T> *&head)
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

template <class T>
void Node<T>::clear(Node<T> *&head)
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

template <class T>
void Node<T>::reverse(Node<T> *&head)
{
    Node<T> *previous = nullptr;
    Node<T> *current = head;
    Node<T> *nextptr;
    while (current != nullptr)
    {
        nextptr = current->next;
        current->next = previous;
        previous = current;
        current = nextptr;
    }
    head = previous;
}

template <class T>
Node<T> *Node<T>::reverseKtimes(Node<T> *&head, int k)
{
    Node<T> *previous = nullptr;
    Node<T> *current = head;
    Node<T> *nextptr;
    int count = 0;
    while (current != nullptr && count < k)
    {
        nextptr = current->next;
        current->next = previous;
        previous = current;
        current = nextptr;
        count++;
    }
    if (nextptr != nullptr) head->next = reverseKtimes(nextptr, k);
    return previous;
}

template <class T>
Node<T> *Node<T>::removeNnodeFromEnd(Node<T> *&head, int n)
{
    if (head == nullptr || n > size(head))
    {
        cout << "Cannot delete " << n << " node because it does not exists" << endl;
        return nullptr;
    }
    Node<T> *slow = head;
    Node<T> *fast = head;
    while (n--) fast = fast->next;
    if (fast == nullptr) return slow->next; // delete and return
    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next; //deleting
    return head;
}

template <class T>
void Node<T>::FindNnodeFromEnd(Node<T> *&head, int n)
{
    if (head == nullptr || n > size(head))
    {
        cout << n << " node does not exists" << endl;
        return;
    }
    Node<T> *slow = head;
    Node<T> *fast = head;
    while (n--) fast = fast->next;
    if (fast == nullptr) 
    {
        cout << slow->data << " is the required node" << endl;
        return;
    }
    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    cout << slow->next->data << " is the required node" << endl;
}

template <class T>
void Node<T>::deleteNnode(Node<T> *&head, int n)
{
    if (head == nullptr) return;
    Node<T> *curr = head;
    Node<T> *prev = nullptr;
    while (curr != nullptr)
    {
        if (curr->data == n)
        {
            if (prev == nullptr) head = curr->next;
            else
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

template <class T>
void Node<T>::sort(Node<T> *head)
{
    if (head == nullptr || head->next == nullptr) return;
    Node *current = head;
    while (current != nullptr)
    {
        Node *min = current;
        Node *temp = current->next;
        while (temp != nullptr) // find smallest
        {
            if (temp->data < min->data) min = temp;
            temp = temp->next;
        }
        swap(current->data,min->data);
        current = current->next;
    }
}

template <class T>
void Node<T>::removeDuplicatesSorted(Node<T> *&head)
{
    if (head == nullptr) return;
    Node<T>* current = head;
    while (current != nullptr) 
    {
        if (current->next != nullptr && current->data == current->next->data) current->next = current->next->next;
        else current = current->next;
    }
}

template <class T>
void Node<T>::removeDuplicatesUnSorted(Node<T> *&head)
{
    if (head == nullptr) return;
    Node<T>* current = head;
    while (current != nullptr) 
    {
        Node<T>* temp = current;
        while (temp->next != nullptr) 
        {
            if (current->data == temp->next->data) temp->next = temp->next->next;
            else temp = temp->next;
        }
        current = current->next;
    }
}

int main()
{
    Node<int> *ll = nullptr;
    ll->insertAtTail(ll, 1);
    ll->insertAtTail(ll, 1);
    ll->insertAtTail(ll, 2);
    ll->insertAtTail(ll, 9);
    ll->insertAtTail(ll, 3);
    ll->insertAtTail(ll, 2);
    ll->insertAtTail(ll, 1);
    ll->insertAtTail(ll, 8);
    ll->insertAtTail(ll, 10);
    ll->insertAtTail(ll, 14);
    ll->insertAtTail(ll, 14);
    ll->display(ll);
    // Node<int> *n = ll->reverseKtimes(ll,2);
    // n->display(n);
    //ll->sort(ll);
    // ll->deleteNnode(ll,9);
    // cout << "Middle Element: " << ll->middleElement(ll) << endl;
    // ll->display(ll);
    // Node<int> *n = ll->mid(ll);
    // cout << n->data << endl;
    // ll->DeletemiddleElement(ll);
    // cout << "Nth node: ";
    // ll->FindNnodeFromEnd(ll, 9);
    ll->removeDuplicatesUnSorted(ll);
    // ll->removeNnodeFromEnd(ll,9);
    ll->display(ll);
    return 0;
}
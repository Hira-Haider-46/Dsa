#include <iostream>
using namespace std;

// chaining method (open hashing/ closed addressing) 

struct Node
{
    int key;
    Node *next;
    Node(int key) : key(key), next(nullptr) {}
};

class HashTable
{
private:
    Node **table;
    int size;
    int hashFunction(int key)
    {
        return key % size;
    }

public:
    HashTable(int size)
    {
        this->size = size;
        table = new Node *[size];
        for (int i = 0; i < size; i++) table[i] = nullptr;
    }
    ~HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            Node *curr = table[i];
            while (curr != nullptr)
            {
                Node *prev = curr;
                curr = curr->next;
                delete prev;
            }
        }
        delete[] table;
    }
    void insertItem(int key)
    {
        int index = hashFunction(key);
        Node *newNode = new Node(key);
        if (table[index] == nullptr) table[index] = newNode;
        else
        {
            Node *temp = table[index];
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }
    }
    bool searchItem(int key) 
    {
        int index = hashFunction(key);
        Node* curr = table[index];
        while (curr != nullptr) 
        {
            if (curr->key == key) return true;
            curr = curr->next;
        }
        return false;
    }
    void deleteItem(int key)
    {
        int index = hashFunction(key);
        Node *curr = table[index];
        Node *prev = nullptr;
        while (curr != nullptr && curr->key != key)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) return;
        else
        {
            if (prev == nullptr) table[index] = curr->next;
            else prev->next = curr->next;
            delete curr;
        }
    }
    void displayHashTable()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << "Index " << i << ": ";
            Node *temp = table[i];
            while (temp != nullptr)
            {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    int keys[] = {15, 11, 27, 8, 12};
    int size = sizeof(keys) / sizeof(keys[0]);
    HashTable hashTable(7);
    for (int i = 0; i < size; i++) hashTable.insertItem(keys[i]);
    hashTable.displayHashTable();
    if (hashTable.searchItem(12)) cout << "Key found in the hash table." << endl;
    else cout << "Key is not found in the hash table." << endl;
    hashTable.deleteItem(12);
    cout << "\nAfter deleting key 12\n";
    hashTable.displayHashTable();
    return 0;
}
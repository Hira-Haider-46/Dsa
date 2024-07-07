#include <iostream>
using namespace std;

// (closed hashing / open addressing) type 1

class HashTable
{
private:
    int *table;
    int size;
    int capacity;
    int hashFunction(int key)
    {
        return key % capacity;
    }

public:
    HashTable(int capacity)
    {
        this->capacity = capacity;
        table = new int[capacity];
        size = 0;
        for (int i = 0; i < capacity; i++) table[i] = -1; // -1 indicates an empty slot
    }
    ~HashTable()
    {
        delete[] table;
    }
    void insertItem(int key)
    {
        if (size == capacity)
        {
            cout << "Hash table is full" << endl;
            return;
        }
        int index = hashFunction(key);
        while (table[index] != -1) index = (index + 1) % capacity; // Linear probing
        table[index] = key;
        size++;
    }
    void deleteItem(int key)
    {
        int index = hashFunction(key);
        while (table[index] != key)
        {
            index = (index + 1) % capacity; // Linear probing
            if (table[index] == -1)
            {
                cout << "Key not found" << endl;
                return;
            }
        }
        table[index] = -1;
        size--;
    }
    void displayHashTable()
    {
        for (int i = 0; i < capacity; i++) cout << i << ": " << table[i] << endl;
    }
};

int main()
{
    HashTable hashTable(7);
    hashTable.insertItem(10);
    hashTable.insertItem(20);
    hashTable.insertItem(15);
    hashTable.insertItem(7);
    hashTable.displayHashTable();
    hashTable.deleteItem(15);
    cout << "\nAfter deleting key 15\n";
    hashTable.displayHashTable();
    return 0;
}
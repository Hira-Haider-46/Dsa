#include <iostream>
using namespace std;

// (closed hashing / open addressing) type 2

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
        int i = 1;
        while (table[index] != -1)
        {
            index = (index + i * i) % capacity;
            i++;
        }
        table[index] = key;
        size++;
    }
    bool searchItem(int key) {
        int index = hashFunction(key);
        int i = 1;
        while (table[index] != key) 
        {
            index = (index + i * i) % capacity;
            i++;
            if (table[index] == -1 || i > capacity) return false;
        }
        return true;
    }
    void deleteItem(int key)
    {
        int index = hashFunction(key);
        int i = 1;
        while (table[index] != key)
        {
            index = (index + i * i) % capacity;
            i++;
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
    if (hashTable.searchItem(15)) cout << "Key found in the hash table." << endl;
    else cout << "Key is not found in the hash table." << endl;
    hashTable.deleteItem(15);
    cout << "\nAfter deleting key 15\n";
    hashTable.displayHashTable();
    return 0;
}
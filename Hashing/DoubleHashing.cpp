#include <iostream>
using namespace std;

// (closed hashing / open addressing) type 3

class HashTable
{
private:
    int *table;
    int size;
    int capacity;
    int hashFunction1(int key)
    {
        return key % capacity;
    }
    int hashFunction2(int key)
    {
        return (7 - (key % 7)); // Second hash function should be different and typically uses a prime number less than the capacity
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
        int index = hashFunction1(key);
        int stepSize = hashFunction2(key);
        while (table[index] != -1)
        {
            index = (index + stepSize) % capacity;
        }
        table[index] = key;
        size++;
    }
    bool searchItem(int key) 
    {
        int index = hashFunction1(key);
        int stepSize = hashFunction2(key);
        while (table[index] != -1) 
        {
            if (table[index] == key) return true;
            index = (index + stepSize) % capacity;
        }
        return false;
    }
    void deleteItem(int key)
    {
        int index = hashFunction1(key);
        int stepSize = hashFunction2(key);
        while (table[index] != key)
        {
            index = (index + stepSize) % capacity;
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
    if (hashTable.searchItem(7)) cout << "Key found in the hash table." << endl;
    else cout << "Key is not found in the hash table." << endl;
    hashTable.deleteItem(15);
    cout << "\nAfter deleting key 15\n";
    hashTable.displayHashTable();
    return 0;
}
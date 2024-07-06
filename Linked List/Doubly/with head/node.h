#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node<T> *next;
    node<T> *prev;
    node(T val) : data(val), next(nullptr), prev(nullptr) {}
    node() : data(T()), next(nullptr), prev(nullptr) {}
};
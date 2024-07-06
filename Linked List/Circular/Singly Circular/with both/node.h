#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node<T> *next;
    node(T val) : data(val), next(nullptr) {}
    node() : data(0), next(nullptr) {}
};
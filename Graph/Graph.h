#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

template <typename T>
class Graph
{
private:
    bool direction;
    int numVertices;                            // Contain Number of vertices in the graph
    unordered_map<T, unordered_set<T>> adjList; // Adjacency list to represent the graph given by user you can also used matrix but it consumes more space than list

public:
    Graph(int vertices, bool dir);
    void addEdge(T startVertex, T endVertex); // Function to add an edge between vertices
    void dfs(T startVertex, bool *);          // Function to perform Depth-First Search
    void bfs(T startVertex);                  // Function to perform Breadth-First Search
    void dfsStart(T startVertex);
};

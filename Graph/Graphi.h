#pragma once

#include "Graph.h"

// Constructor to initializein  the graph.h with the specified number of vertices
template <typename T>
Graph<T>::Graph(int vertices, bool dir)
{
    direction = dir;
    numVertices = vertices;
}

// Function to add an edge between two vertices
template <typename T>
void Graph<T>::addEdge(T startVertex, T endVertex)
{
    adjList[startVertex].insert(endVertex); // Add endVertex to startVertex's list
    if (direction == false)
        adjList[endVertex].insert(startVertex); // Add startVertex to endVertex's list for the  (undirected graph)
}

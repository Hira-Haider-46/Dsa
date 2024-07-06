#pragma once
#include "Graphi.h"            // Assuming Graphi.h contains the Graph class definition
#include "./Stack/StackImpl.h" // Assuming StackImpl.h contains the Stack implementation

template <typename T>
void Graph<T>::dfs(T startVertex, bool *visited)
{
    StackImpl<T> stack; // Using StackImpl<T> to simulate stack behavior

    stack.push(startVertex); // Start DFS with the initial vertex or starting node

    cout << "DFS Traversal starting from vertex " << startVertex << ": ";

    while (!stack.isEmpty())
    {
        T currentVertex = stack.peek(); // Get the top element from the stack
        stack.pop();                    // Remove the top element

        if (!visited[currentVertex])
        {
            cout << currentVertex << " ";
            visited[currentVertex] = true;

            // Traverse all adjacent vertices
            for (auto it = adjList[currentVertex].begin(); it != adjList[currentVertex].end(); ++it)
            {
                if (!visited[*it]) stack.push(*it);
            }
        }
    }
    cout << endl;
}

template <typename T>
void Graph<T>::dfsStart(T startVertex)
{
    bool *visited = new bool[numVertices + 1]; // Allocate memory to track visited vertices
    for (int i = 0; i < numVertices + 1; i++) visited[i] = false; // Initialize all vertices as not visited

    dfs(startVertex, visited); // Start DFS from the specified startVertex

    // Check and perform DFS for any disconnected components
    for (const auto &pair : adjList)
    {
        if (!visited[pair.first]) dfs(pair.first, visited);
    }

    delete[] visited; // Free allocated memory
}

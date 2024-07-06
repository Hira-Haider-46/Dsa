#pragma once
#include "Graphi.h"
#include "./Queue/QueueImpl.h"
// Breadth-First Search
template <typename T>
void Graph<T>::bfs(T startVertex)
{
    // Check if startVertex exists in the adjacency list
    if (adjList.find(startVertex) == adjList.end())
    {
        cout << "Vertex " << startVertex << " does not exist in the graph." << endl;
        return;
    }
    bool *visited = new bool(numVertices + 1); // To keep record  of visited vertices
    for (int i = 0; i < numVertices + 1; i++) visited[i] = false;
    QueueImpl<int> queue; // Using queue behavior
    queue.enqueue(startVertex);  // Start BFS with the initial vertex or starting node
    visited[startVertex] = true; // Mark it as visited if already performed
    cout << "BFS Traversal starting from vertex " << startVertex << ": ";
    while (!queue.isEmpty())
    {
        int currentVertex = queue.peek(); // Get the front element from the queue
        queue.dequeue();                  // Remove the front element
        cout << currentVertex << " ";
        // Enqueue all adjacent unvisited vertices
        for (auto it = adjList[currentVertex].begin(); it != adjList[currentVertex].end(); ++it)
        {
            if (!visited[*it])
            {
                queue.enqueue(*it);  // Add to the end to simulate queue
                visited[*it] = true; // Mark them as visited
            }
        }
    }
    cout << endl;
}

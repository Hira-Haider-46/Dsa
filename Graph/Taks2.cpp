#include "Graph.h"
#include "Graphi.h"
#include "Dfs.h"
#include "BFs.h"

#include <iostream>
void displayMenu();
template<typename T>
void handleMenuSelection(Graph<T> &graph, int numVertices);

int main()
{
    int numVertices;

    // Ask the user for the number of vertices in the graph
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;
    cout << "Do you want to build a directed graph(press 1) or Undirected graph(press 0): ";
    int a;
    while (1)
    {
        cin >> a;
        if(a!=0 && a!=1){
            cout<<"Please enter again: ";
            continue;
        }
        break;
    }
    bool direction=false;
    if(a==1){
        direction=true;
    }
    // Create a graph with the given number of vertices
    Graph<int> graph(numVertices,direction);

    // Display the menu and handle user inputs
    handleMenuSelection<int>(graph, numVertices);

    return 0;
}

// Function to display the menu options
void displayMenu()
{
    cout << "\n--- Graph Menu ---\n";
    cout << "1. Add Edge\n";
    cout << "2. Perform DFS\n";
    cout << "3. Perform BFS\n";
    cout << "4. Exit\n";
    cout << "Please enter your choice: ";
}

// Function to handle the menu selection
template<typename T>
void handleMenuSelection(Graph<T> &graph, int numVertices)
{
    int choice;
    int startVertex, endVertex;
    int start;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the starting vertex of the edge: ";
            cin >> startVertex;
            if (startVertex > numVertices)
            {
                cout << "Please enter value less then the number of vertix" << endl;
                continue;
            }
            cout << "Enter the ending vertex of the edge: ";
            cin >> endVertex;
            if (endVertex > numVertices)
            {
                cout << "Please enter value less then the number of vertix" << endl;
                continue;
            }
            graph.addEdge(startVertex, endVertex);
            cout << "Edge added between " << startVertex << " and " << endVertex << ".\n";
            break;

        case 2:
            cout << "Enter the starting vertex for DFS: ";
            cin >> start;

            graph.dfsStart(start);
            break;

        case 3:
            cout << "Enter the starting vertex for BFS: ";
            cin >> start;
            
            graph.bfs(start);
            break;

        case 4:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice! Please enter a valid option.\n";
            break;
        }
    } while (choice != 4);
}

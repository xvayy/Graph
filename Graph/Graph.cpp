#include <iostream>
#include <queue>
#include <stack> 
using namespace std;

const int V = 6;

void BFS(int graph[V][V], int start) {
    bool visited[V]; // Array to mark visited vertices
    for (int i = 0; i < V; i++)
        visited[i] = false;

    queue<int> q; // Creating a queue to store vertices
    visited[start] = true; // Marking the starting vertex as visited
    q.push(start); // Adding the starting vertex to the queue

    while (!q.empty()) {
        int current = q.front(); // Selecting a vertex from the front of the queue
        cout << (current + 1) << ' ';
        q.pop(); // Removing the current vertex from the queue

        for (int i = 0; i < V; i++) {
            if (graph[current][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int graph[V][V], int start) {
    bool visited[V]; // Array to mark visited vertices
    for (int i = 0; i < V; i++)
        visited[i] = false;

    stack<int> s; // Creating a stack to store vertices
    s.push(start); // Adding the starting vertex to the stack

    while (!s.empty()) {
        int current = s.top(); // Selecting a vertex from the top of the stack
        s.pop(); // Removing the current vertex from the stack

        if (!visited[current]) {
            cout << (current + 1) << ' ';
            visited[current] = true;
        }

        for (int i = 0; i < V; i++) { 
            if (graph[current][i] && !visited[i]) { // If there's an edge and vertex is not visited
                s.push(i); // Adding vertex to the stack
            }
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0}
    };

    cout << "BFS: ";
    BFS(graph, 0);
    cout << "\nDFS: ";
    DFS(graph, 0);

    return 0;
}

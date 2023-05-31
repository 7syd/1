#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <limits>

using namespace std;

void BFS(map<int, set<int> >& graph, map<int, bool>& visited, int startNode) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        // Iterate through all the adjacent nodes
        for (set<int>::iterator it = graph[currentNode].begin(); it != graph[currentNode].end(); ++it) {
            int adjacentNode = *it;
            // If the adjacent node is not visited, mark it as visited and enqueue it
            if (!visited[adjacentNode]) {
                visited[adjacentNode] = true;
                q.push(adjacentNode);
            }
        }
    }
}

int main() {
    // Create a map to represent the graph
    map<int, set<int> > graph;

    // Take input for the number of nodes
    int numNodes;
    cout << "Enter the number of nodes: ";
    while (!(cin >> numNodes) || numNodes <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // Take input for the connections between landmarks
    int landmark1, landmark2;
    cout << "Enter the connections between landmarks (enter -1 -1 to stop):\n";
    while (cin >> landmark1 >> landmark2 && (landmark1 != -1 || landmark2 != -1)) {
        graph[landmark1].insert(landmark2);
        graph[landmark2].insert(landmark1);
    }

    // Perform Breadth-First Search (BFS) using the adjacency list
    int startNode;
    map<int, bool> visitedBFS;
    cout << "Enter the starting node for BFS: ";
    while (!(cin >> startNode) || graph.find(startNode) == graph.end()) {
        cout << "Invalid node. Please enter a valid node: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "BFS traversal: ";
    BFS(graph, visitedBFS, startNode);
    cout << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

// Function to perform Depth First Search (DFS)
void DFS(vector<vector<int> >& graph, map<int, string>& landmarks, int startNode) {
    int numNodes = graph.size();

    vector<bool> visited(numNodes, false);
    stack<int> dfsStack;

    dfsStack.push(startNode);
    visited[startNode] = true;

    cout << "DFS traversal starting from " << landmarks[startNode] << ":" << endl;

    while (!dfsStack.empty()) {
        int currentNode = dfsStack.top();
        dfsStack.pop();

        cout << landmarks[currentNode] << " ";

        for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
            if (graph[currentNode][neighbor] == 1 && !visited[neighbor]) {
                dfsStack.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    cout << endl;
}

int main() {
    // Create the graph using an adjacency matrix
    vector<vector<int> > graph;
    graph.resize(6, vector<int>(6, 0));
    graph[0][1] = 1;
    graph[0][4] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[2][5] = 1;
    graph[3][1] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;
    graph[4][0] = 1;
    graph[4][1] = 1;
    graph[4][3] = 1;
    graph[4][5] = 1;
    graph[5][2] = 1;
    graph[5][4] = 1;

    
    map<int, string> landmarks;
    landmarks[0] = "Park";
    landmarks[1] = "Library";
    landmarks[2] = "Cafeteria";
    landmarks[3] = "Auditorium";
    landmarks[4] = "Sports_Complex";
    landmarks[5] = "Hostel";

    int startNode = 0; 

    
    DFS(graph, landmarks, startNode);

    return 0;
}


#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Function to perform Breadth First Search (BFS)
void BFS(vector<vector<int> >& graph, map<int, string>& landmarks, int startNode) {
    int numNodes = graph.size();

    vector<bool> visited(numNodes, false);
    queue<int> bfsQueue;

    bfsQueue.push(startNode);
    visited[startNode] = true;

    cout << "BFS traversal starting from " << landmarks[startNode] << ":" << endl;

    while (!bfsQueue.empty()) {
        int currentNode = bfsQueue.front();
        bfsQueue.pop();

        cout << landmarks[currentNode] << " ";

        for (int i = 0; i < graph[currentNode].size(); ++i) {
            int neighbor = graph[currentNode][i];
            if (!visited[neighbor]) {
                bfsQueue.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    cout << endl;
}

int main() {
    // Create the graph using an adjacency list
    vector<vector<int> > graph(6);

    graph[0].push_back(1);
    graph[0].push_back(4);

    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);

    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(5);

    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[3].push_back(4);

    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(2);
    graph[5].push_back(4);

    // Create a map of landmarks
    map<int, string> landmarks;
    landmarks[0] = "Park";
    landmarks[1] = "Library";
    landmarks[2] = "Cafeteria";
    landmarks[3] = "Auditorium";
    landmarks[4] = "Sports_Complex";
    landmarks[5] = "Hostel";

    int startNode = 0; // Starting node for BFS

    // Perform BFS on the graph
    BFS(graph, landmarks, startNode);

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    // Constructor
    Graph(int V) {
        vertices = V;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    // Add edge (0-based indexing)
    void addEdge(int u, int v, bool directed = false) {
        adjMatrix[u][v] = 1;
        if (!directed) {
            adjMatrix[v][u] = 1;
        }
    }

    // Print adjacency matrix
    void printGraph() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V = 5; // Number of vertices
    Graph g(V);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print the graph
    g.printGraph();

    return 0;
}

OUTPUT :-
Adjacency Matrix:
0 1 0 0 1
1 0 1 1 1
0 1 0 1 0
0 1 1 0 1
1 1 0 1 0


#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

template <typename T>

class Graph {
  public:
  unordered_map<T,list<T>>adjList;

  void addEdge(T u,T v,bool direction){
       if(direction==1){
           adjList[u].push_back(v);
       }
       else{
           adjList[u].push_back(v);
           adjList[v].push_back(u);
       }
  }
  void printAdjList(){
      for(auto i: adjList){
        cout << i.first << "-> {";
        for(auto neighbour: i.second){
          cout << neighbour <<",";
        }
        cout << "}" << endl;
      }
  }    
  
  void bfsTraversal(T src){
      
      unordered_map<T,bool> visited;
      queue<T> q;
      
      q.push(src);
      visited[src] = true;
      
      while(!q.empty()){
          T frontNode = q.front();
          cout << frontNode << " ";
          q.pop();
          
          for(auto nbr: adjList[frontNode]){
              if(!visited[nbr]){
                  q.push(nbr);
                  visited[nbr] = true;
              }
          }
      }
  }
  
    void bfsTraversalForDis(T src,unordered_map<T,bool>&visited){

      queue<T> q;
      
      q.push(src);
      visited[src] = true;
      
      while(!q.empty()){
          T frontNode = q.front();
          cout << frontNode << " ";
          q.pop();
          
          for(auto nbr: adjList[frontNode]){
              if(!visited[nbr]){
                  q.push(nbr);
                  visited[nbr] = true;
              }
          }
      }
  }
};

int main() {
  
  Graph<char> g;
//   g.addEdge('a','b',1);
//   g.addEdge('b','c',1);
//   g.addEdge('b','d',0);
//   g.addEdge('c','d',1);
  
//   g.bfsTraversal('a');


//FOR-DIS-CONNECTED-GRAPH
g.addEdge('a','b',1);
g.addEdge('b','c',1);
g.addEdge('d','e',1);
g.addEdge('f','f',1);

unordered_map<char,bool> visited;
for(char node='a';node<='f';node++){
    if(!visited[node]){
       g.bfsTraversalForDis(node,visited);
    }
}
//   cout << "Printing Adjacency List: " << endl;
//   g.printAdjList();

  return 0;
}




//2ND CODE MORE EFFICIENT APPROACH
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int startNode, const vector<vector<int>>& adjList, int V) {
    vector<bool> visited(V + 1, false);  // +1 to handle 1-based indexing
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal starting from node " << startNode << ": ";

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int neighbor : adjList[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices (V): ";
    cin >> V;
    cout << "Enter number of edges (E): ";
    cin >> E;

    vector<vector<int>> adjList(V + 1);  // +1 for 1-based indexing

    cout << "Enter edges (u v) for a directed graph:\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        // For undirected graph, also add:
        // adjList[v].push_back(u);
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    bfs(startNode, adjList, V);

    return 0;
}


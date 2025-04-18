
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
    
  void dfsTraversal(T src,unordered_map<T,bool> &visited){
      visited[src] = true;
      cout << src << " ";
      
      for(auto nbr: adjList[src]){
          if(!visited[nbr]){
              dfsTraversal(nbr,visited);
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
g.addEdge('f','g',1);

unordered_map<char,bool> visited;
int count = 0;

for(char node='a';node<='g';node++){
    if(!visited[node]){
        g.dfsTraversal(node,visited);
        count++;
    }
}
cout << endl;
cout << "Number of dis-connected components in this graph is :" << count << endl;
  
return 0;
}

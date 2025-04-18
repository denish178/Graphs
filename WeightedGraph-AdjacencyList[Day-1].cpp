#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

template <typename T>

class Graph {
  
  public:

  unordered_map<T,list<pair<T,int>>> adjList;

  void addEdge(T u,T v,int wt,bool direction){

    if(direction==1){
      adjList[u].push_back(make_pair(v,wt));
    }
    else {
      adjList[u].push_back(make_pair(v,wt));
      adjList[v].push_back(make_pair(u,wt)); 
    }
  }


  void printAdjList(){
    for(auto i:adjList){
      cout << i.first << ": ";
      for(pair<T,int> p: i.second){
        cout << "{"<<p.first << ","<< p.second << "},";
      }
      cout << endl;
    }
  }


};

int main() {
  
  Graph<int> g;
  g.addEdge(0,1,5,1);
  g.addEdge(1,2,10,1);
  g.addEdge(1,3,20,1);
  g.addEdge(2,3,50,1);

  cout << "Printing Adjacency List: " << endl;
  g.printAdjList();

  return 0;
}

Representation | Space Complexity | Time Complexity (Creation) | Best for
Adjacency List | O(V + E) | O(V + E) | Sparse graphs
Adjacency Matrix | O(V²) | O(V²) | Dense graphs

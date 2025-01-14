#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Graph {
  public:
  unordered_map<int,list<int>>adjList;

  void addEdge(int u,int v,bool direction){
       if(direction==1){
           adjList[u].push_back(v);
       }
       else{
           adjList[u].push_back(v);
           adjList[v].push_back(u);
       }
       cout << endl << "Printing adjList" << endl;
       printAdjList();
       cout << endl;
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
};

int main() {
  
  Graph g;
  g.addEdge(0,1,1);
  g.addEdge(1,2,1);
  g.addEdge(2,3,0);
  g.addEdge(3,4,1);

  return 0;
}

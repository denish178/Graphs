   void dfs(int src,map<int,bool> &visited,unordered_map<int,list<int>> &adjList,stack<int> &st){
       visited[src] = true;
       
       for(auto nbr: adjList[src]){
           if(!visited[nbr]){
               dfs(nbr,visited,adjList,st);
           }
       }
       st.push(src);
   }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        unordered_map<int,list<int>> adjList;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adjList[u].push_back(v);
        }
        stack<int> st;
        map<int,bool> visited;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,adjList,st);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    bool solve(int src,vector<bool>& vis,vector<vector<int>>& adj){
        
        unordered_map<int,int> parent;
        queue<int> q;
        
        q.push(src);
        vis[src] = true;
        parent[src] = -1;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(auto nbr: adj[frontNode]){
                if(!vis[nbr]){
                    vis[nbr] = true;
                    parent[nbr] = frontNode;
                    q.push(nbr);
                }
                else if(vis[nbr] && nbr != parent[frontNode]){
                    return true;
                }
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        
        vector<bool> vis(V, false);
        
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool ans = solve(i,vis,adj);
                if(ans) return true;
            }
        }
        return false;
    }

bool solve(int src, vector<bool>& visited, int parent, vector<vector<int>>& adj) {
    visited[src] = true;
    
    for (auto nbr : adj[src]) {
        // If the neighbor is not visited, recurse
        if (!visited[nbr]) {
            bool ans = solve(nbr, visited, src, adj);
            if (ans) return true;
        }
        // If the neighbor is visited and is not the parent, a cycle is detected
        else if (nbr != parent) {
            return true;
        }
    }
    return false;
}

// Function to detect cycle in an undirected graph
bool isCycle(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);  // To track visited nodes
    
    for (int i = 0; i < V; i++) {
        // If the node is not visited, start DFS from it
        if (!visited[i]) {
            bool ans = solve(i, visited, -1, adj);
            if (ans) return true;
        }
    }
    return false;
}

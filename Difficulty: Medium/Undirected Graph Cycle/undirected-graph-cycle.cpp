class Solution {
  public:
    bool bfsHelper(int start, vector<vector<int>> &adj, vector<bool> &visited){
        queue<int> q;
        vector<int> parent(adj.size(), -1);
        
        visited[start] = true;
        q.push(start);
        parent[start] = -1;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for (int neighbour : adj[frontNode]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                    parent[neighbour] = frontNode;
                }
                else  if (parent[frontNode] != neighbour) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(bfsHelper(i, adj, visited))
                return true;
                
            }
        }
        return false;
    }
    
};
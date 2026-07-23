class Solution {
  public:
    bool dfsHelper(int node , vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &rec){
        visited[node] = true;
        rec[node] = true;
        
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                if(dfsHelper(neighbour, adj, visited, rec)){
                    return true;
                }
            }
            else if(rec[neighbour]){
                return true;
            }
        }
        rec[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for (auto i : edges){
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
        }
        vector<bool> visited(V, false);
        vector<bool> rec(V, false);
        
        for(int i = 0; i< V; i++){
            if(!visited[i]){
                if(dfsHelper(i, adj, visited, rec)){
                    return true;
                }
            }
        }
        return false;
    }
};
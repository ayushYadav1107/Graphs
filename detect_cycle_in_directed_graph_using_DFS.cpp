class Solution {
  public:
    bool isCycleDFS(unordered_map<int,vector<int>>&adj,int u, vector<bool>&visited,vector<bool>&inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        
        for(auto &it : adj[u]){
            if(!visited[it] && isCycleDFS(adj,it,visited,inRecursion)==true){
                return true;
            }else if(inRecursion[it]){
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
        
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<int>>adj;
        int n = edges.size();
        
        for(int i = 0; i < n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<bool>visited(V,false);
        vector<bool>inRecursion(V,false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i] && isCycleDFS(adj,i,visited,inRecursion)){
                return true;
            }
        }
        return false;
    }
};
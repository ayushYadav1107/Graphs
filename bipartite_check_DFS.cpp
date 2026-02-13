class Solution {
  public:
  
    bool DFS(unordered_map<int,vector<int>>&adj,int curr,vector<int>&color,int currColor){
        color[curr] = currColor;
        
        for(int &v : adj[curr]){
            if(color[v]==color[curr]){ // color matches
                return false;
            }
            
            if(color[v]==-1){
                color[v] = 1 - color[curr]; // to set the opposite color
                
                if(DFS(adj,v,color,color[v])==false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        unordered_map<int,vector<int>> adj;
        int n = edges.size();
        for(int i = 0; i < n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //color vector
        vector<int>color(V,-1);
        // Red - > 1
        // Green -> 0
        for(int i = 0; i < V; i++){
            if(color[i]==-1){
                if(DFS(adj,i,color,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
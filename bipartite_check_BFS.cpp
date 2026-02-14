class Solution {
  public:
  
    bool BFS(unordered_map<int,vector<int>>&adj,int curr,vector<int>&color,int currColor){
        queue<int>q;
        q.push(curr);
        color[curr] = currColor;
        
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            
            for(int &v : adj[currNode]){
                if(color[v] == color[currNode]){
                    return false;
                }
                
                if(color[v] == -1){
                    color[v] = 1 - color[currNode];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
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
        return BFS(adj,0,color,1);
    }
};
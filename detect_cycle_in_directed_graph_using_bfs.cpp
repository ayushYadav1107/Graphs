class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<int>>adj;
        int n = edges.size();
        
        for(int i = 0; i < n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int>inDegree(V,0);
        queue<int>q;
        
        for(int i = 0; i < V; i++){
            for(auto &it : adj[i]){
                inDegree[it]++;
            }
        }
        
        for(int i = 0; i < V; i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            
            for(auto &it : adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
            
        }
        if(count==V) return false;
        return true;
    }
};